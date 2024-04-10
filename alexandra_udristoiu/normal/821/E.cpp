#include<iostream>
#define mod 1000000007
using namespace std;
int n, m, i, j, ii, jj;
long long k, b, c, p;
int d[105][20], a[20][20], r[20][20], aux[20][20];
void copiere(int a[20][20], int b[20][20]){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = b[i][j];
        }
    }
}
void mult(int a[20][20], int b[20][20], int c[20][20]){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            c[i][j] = 0;
            for(int ii = 1; ii <= m; ii++){
                c[i][j] = (a[i][ii] * 1LL * b[ii][j] + c[i][j]) % mod;
            }
        }
    }
}
int main(){
    cin>> n >> k;
    d[0][1] = 1;
    for(i = 1; i <= n; i++){
        cin>> b >> c >> m;
        c = min(c, k);
        m++;
        for(j = 1; j <= m; j++){
            r[j][j] = 1;
            a[j][j] = 1;
            if(j != 1){
                a[j][j - 1] = 1;
            }
            if(j != m){
                a[j][j + 1] = 1;
            }
        }
        p = c - b;
        while(p != 0){
            if(p % 2 == 1){
                mult(a, r, aux);
                copiere(r, aux);
            }
            mult(a, a, aux);
            copiere(a, aux);
            p /= 2;
        }
        for(ii = 1; ii <= m; ii++){
            for(jj = 1; jj <= m; jj++){
                d[i][ii] = (r[ii][jj] * 1LL * d[i - 1][jj] + d[i][ii]) % mod;
            }
        }
        for(ii = 1; ii <= m; ii++){
            for(jj = 1; jj <= m; jj++){
                a[ii][jj] = r[ii][jj] = 0;
            }
        }
    }
    cout<< d[n][1];
    return 0;
}