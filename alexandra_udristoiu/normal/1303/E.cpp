#include<iostream>
#include<cstring>
using namespace std;
int t, n, m, i, j, k;
char s[405], c[405];
int d[405][405], nxt[405][200];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        cin>> c + 1;
        m = strlen(c + 1);
        for(j = 'a'; j <= 'z'; j++){
            nxt[n + 1][j] = n + 1;
        }
        for(i = n; i >= 0; i--){
            for(j = 'a'; j <= 'z'; j++){
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][ s[i + 1] ] = i + 1;
        }
        for(k = 1; k <= m; k++){
            d[0][k] = 0;
            for(i = 0; i <= k; i++){
                for(j = k; j <= m; j++){
                    if(i == 0 && j == k){
                        continue;
                    }
                    d[i][j] = n + 1;
                    if(i != 0){
                        d[i][j] = nxt[ d[i - 1][j] ][ c[i] ];
                    }
                    if(j != k){
                        d[i][j] = min(d[i][j], nxt[ d[i][j - 1] ][ c[j] ]);
                    }
                }
            }
            if(d[k][m] <= n){
                break;
            }
        }
        if(k <= m){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}