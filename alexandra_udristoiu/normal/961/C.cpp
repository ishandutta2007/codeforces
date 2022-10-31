#include<iostream>
using namespace std;
int n, i, j, ii, sol;
char a[5][105][105];
int v[6], ff[6];
int solve(int x){
    int nr = 0;
    for(int i = 1; i <= n + n; i++){
        for(int j = 1; j <= n + n; j++){
            int y;
            if(i <= n && j <= n){
                y = a[ v[1] ][i][j];
            }
            if(i <= n && j > n){
                y = a[ v[2] ][i][j - n];
            }
            if(i > n && j <= n){
                y = a[ v[3] ][i - n][j];
            }
            if(i > n && j > n){
                y = a[ v[4] ][i - n][j - n];
            }
            if( (x + i + j) % 2 != y){
                nr++;
            }
        }
    }
    return nr;
}
void backt(int p){
    if(p == 5){
        sol = min(sol, solve(0));
        sol = min(sol, solve(1));
    }
    else{
        for(int i = 1; i <= 4; i++){
            if(ff[i] == 0){
                v[p] = i;
                ff[i] = 1;
                backt(p + 1);
                ff[i] = 0;
            }
        }
    }
}
int main(){
    cin>> n;
    sol = 4 * n * n;
    for(ii = 1; ii <= 4; ii++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                cin>> a[ii][i][j];
                a[ii][i][j] -= '0';
            }
        }
    }
    backt(1);
    cout<< sol;
}