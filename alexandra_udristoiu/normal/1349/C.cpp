#include<iostream>
using namespace std;
int n, m, q, i, j, p, u, ii, jj, iv, jv, ok, d;
long long t;
int c[1000005][2], num[1005][1005];
char a[1005][1005];
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
int main(){
    cin>> n >> m >> q;
    for(i = 1; i <= n; i++){
        cin>> a[i] + 1;
    }
    p = 1;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            ok = 0;
            for(d = 0; d < 4; d++){
                if(a[i][j] == a[ di[d] + i ][ dj[d] + j ]){
                    ok = 1;
                    break;
                }
            }
            if(ok == 1){
                u++;
                c[u][0] = i;
                c[u][1] = j;
                num[i][j] = 1;
            }
        }
    }
    while(p <= u){
        ii = c[p][0];
        jj = c[p][1];
        p++;
        for(d = 0; d < 4; d++){
            iv = ii + di[d];
            jv = jj + dj[d];
            if(iv >= 1 && iv <= n && jv >= 1 && jv <= m && a[iv][jv] != a[ii][jj] && num[iv][jv] == 0){
                num[iv][jv] = 1 + num[ii][jj];
                u++;
                c[u][0] = iv;
                c[u][1] = jv;
            }
        }
    }
    for(; q; q--){
        cin>> ii >> jj >> t;
        if(num[ii][jj] > t || num[ii][jj] == 0){
            cout<< a[ii][jj] <<"\n";
        }
        else{
            if( (t - num[ii][jj]) % 2 == 1){
                cout<< a[ii][jj] <<"\n";
            }
            else{
                cout<< (char) ('1' + '0' - a[ii][jj]) <<"\n";
            }
        }
    }
}