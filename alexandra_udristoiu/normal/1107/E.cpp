#include<iostream>
using namespace std;
int n, i, j, ii, jj, lg, t;
int v[105];
char s[105];
long long d[105][105][105][2];
int main(){
    cin>> n;
    cin>> s + 1;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            for(ii = 0; ii <= n; ii++){
                d[i][j][ii][0] = d[i][j][ii][1] = -100000000000000LL;
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            if(s[i] != s[j]){
                break;
            }
            d[i][j][j - i + 1][ s[i] - '0' ] = 0;
        }
    }
    for(lg = 1; lg <= n; lg++){
        for(i = 1; i <= n - lg + 1; i++){
            j = i + lg - 1;
            for(ii = 0; ii <= j - i + 1; ii++){
                for(t = 0; t < 2; t++){
                    for(jj = i; jj < j; jj++){
                        if(ii >= jj - i + 1){
                            d[i][j][ii][t] = max(d[i][j][ii][t], d[i][jj][jj - i + 1][t] + d[jj + 1][j][ii - (jj - i + 1)][t]);
                        }
                        d[i][j][ii][t] = max(d[i][j][ii][t], d[i][jj][0][t] + d[jj + 1][j][ii][t]);
                    }
                }
            }
            for(ii = 0; ii <= j - i + 1; ii++){
                for(jj = ii + 1; jj <= j - i + 1; jj++){
                    for(t = 0; t < 2; t++){
                        d[i][j][ii][t] = max(d[i][j][ii][t], d[i][j][jj][t] + v[jj - ii]);
                    }
                }
            }
            d[i][j][0][0] = max(d[i][j][0][0], d[i][j][0][1]);
            d[i][j][0][1] = max(d[i][j][0][0], d[i][j][0][1]);
        }
    }
    cout<< d[1][n][0][0];
    return 0;
}