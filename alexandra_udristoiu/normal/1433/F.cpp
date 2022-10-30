#include<iostream>
using namespace std;
int n, m, k, i, j, nr, p, sol;
int a[75][75], d[72][72][72][72];
int main(){
    cin>> n >> m >> k;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin>> a[i][j];
        }
    }
    for(i = 0; i <= n; i++){
        for(j = 0; j <= m; j++){
            for(nr = 0; nr <= m; nr++){
                for(p = 0; p <= k; p++){
                    d[i][j][nr][p] = -1000000000;
                }
            }
        }
    }
    d[0][m][0][0] = 0;
    for(i = 1; i <= n; i++){
        for(p = 0; p < k; p++){
            for(nr = 0; nr <= m / 2; nr++){
                d[i][0][0][p] = max(d[i][0][0][p], d[i - 1][m][nr][p]);
            }
        }
        for(j = 1; j <= m; j++){
            for(nr = 0; nr <= min(j, m / 2); nr++){
                for(p = 0; p < k; p++){
                    d[i][j][nr][p] = d[i][j - 1][nr][p];
                    if(nr != 0){
                        d[i][j][nr][p] = max(d[i][j][nr][p], a[i][j] + d[i][j - 1][nr - 1][ (k + p - a[i][j] % k) % k ]);
                    }
                }
            }
        }
    }
    for(j = 0; j <= m / 2; j++){
        sol = max(sol, d[n][m][j][0]);
    }
    sol = max(sol, 0);
    cout<< sol;
}