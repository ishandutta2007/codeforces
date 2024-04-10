#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
int n, m, i, j, nr, nod, x, y, sol;
int r[2005], df[2005][4005], ds[2005][4005], c[2005], viz[2005], r2[2005][2];
vector<int> v[2005];
int calc(int i, int x, int y){
    int j, sum, dif, jj;
    dif = x - y;
    sum = 0;
    for(j = -n; j <= n; j++){
        jj = dif - j;
        sum = (sum + df[i - 1][j + n] * 1LL * ds[i + 1][jj + n]) % mod;
    }
    return sum;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    viz[1] = 1;
    for(i = 2; i <= n; i++){
        if(viz[i] == 0 && (v[i][0] == 1 || v[i][1] == 1) ){
            c[++nr] = 1;
            x = i;
            while(viz[x] == 0){
                viz[x] = 1;
                c[nr]++;
                if(viz[ v[x][0] ] == 0){
                    x = v[x][0];
                }
                else{
                    x = v[x][1];
                }
            }
        }
    }
    sol = 0;
    df[0][n] = 1;
    for(i = 1; i <= nr; i++){
        for(j = 0; j <= 2 * n; j++){
            df[i][j] = df[i - 1][j];
            if(j - c[i] >= 0){
                df[i][j] = (df[i - 1][ j - c[i] ] + df[i][j]) % mod;
            }
            if(j + c[i] <= 2 * n){
                df[i][j] = (df[i - 1][ j + c[i] ] + df[i][j]) % mod;
            }
        }
    }
    ds[nr + 1][n] = 1;
    for(i = nr; i >= 1; i--){
        for(j = 0; j <= 2 * n; j++){
            ds[i][j] = ds[i + 1][j];
            if(j - c[i] >= 0){
                ds[i][j] = (ds[i + 1][ j - c[i] ] + ds[i][j]) % mod;
            }
            if(j + c[i] <= 2 * n){
                ds[i][j] = (ds[i + 1][ j + c[i] ] + ds[i][j]) % mod;
            }
        }
    }
    for(i = 1; i <= nr; i++){
        for(j = 1; j < c[i]; j++){
            sol = (sol + calc(i, j, c[i] - j) ) % mod;
            if(c[i] - j - 1 != 0){
                sol = (sol + calc(i, j, c[i] - j - 1) ) % mod;
            }
        }
    }
    sol = sol * 2 % mod;
    if(m % 2 == 0){
        r[0] = 1;
        for(i = 1; i <= nr; i++){
            for(j = m / 2; j >= c[i]; j--){
                r[j] = (r[j] + r[ j - c[i] ]) % mod;
            }
        }
        sol = (sol + r[m / 2]) % mod;
    }
    else{
        r2[0][0] = 1;
        for(i = 1; i <= nr; i++){
            for(j = m / 2 + 1; j >= c[i]; j--){
                r2[j][0] = (r2[j][0] + r2[ j - c[i] ][0]) % mod;
                r2[j][1] = (r2[j][1] + r2[ j - c[i] ][1]) % mod;
                r2[j][1] = (r2[j][1] + r2[ j - c[i] ][0] * 2LL) % mod;
            }
        }
        sol = (sol + r2[m / 2 + m % 2][1] * 2LL) % mod;
    }
    cout<< sol;
}