#include<iostream>
using namespace std;
int n, i, j, ii;
int d[105][105][105][2], v[105];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(ii = 0; ii <= n; ii++){
        for(i = 0; i <= n / 2 + 1; i++){
            for(j = 0; j <= n - n / 2 + 1; j++){
                d[ii][i][j][0] = d[ii][i][j][1] = n + 1;
            }
        }
    }
    d[0][n / 2][n - n / 2][0] = d[0][n / 2][n - n / 2][1] = 0;
    for(ii = 1; ii <= n; ii++){
        for(i = 0; i <= n / 2; i++){
            for(j = 0; j <= n - n / 2; j++){
                if(v[ii] != 0){
                    if(v[ii] % 2 == 0){
                        d[ii][i][j][0] = min(d[ii - 1][i + 1][j][0], d[ii - 1][i + 1][j][1] + 1);
                    }
                    else{
                        d[ii][i][j][1] = min(d[ii - 1][i][j + 1][1], d[ii - 1][i][j + 1][0] + 1);
                    }
                }
                else{
                    d[ii][i][j][0] = min(d[ii - 1][i + 1][j][0], d[ii - 1][i + 1][j][1] + 1);
                    d[ii][i][j][1] = min(d[ii - 1][i][j + 1][1], d[ii - 1][i][j + 1][0] + 1);
                }
            }
        }
    }
    cout<< min(d[n][0][0][0], d[n][0][0][1]);
}