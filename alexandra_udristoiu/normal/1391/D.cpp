#include<iostream>
#define DIM 1000005
using namespace std;
int n, m, i, j, t, ii, jj, sol;
char a[DIM][4];
int d[2][10];
int calc(int i, int ii){
    int nr = 0;
    for(int j = 1; j <= 3; j++){
        if(a[i][j] - '0' != ii % 2){
            nr++;
        }
        ii /= 2;
    }
    return nr;
}
int verif(int ii, int jj){
    return (ii % 2 + ii / 2 + jj % 2 + jj / 2) % 2;
}
int main(){
    cin>> n >> m;
    if(n >= 4 && m >= 4){
        cout<< -1;
        return 0;
    }
    if(n > m){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                cin>> a[i][j];
            }
        }
    }
    else{
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                cin>> a[j][i];
            }
        }
        swap(n, m);
    }
    if(m == 1){
        cout<< 0;
        return 0;
    }
    if(m == 2){
        for(i = 1; i <= n; i++){
            d[t][0] = d[1 - t][1];
            d[t][1] = d[1 - t][0];
            if(a[i][1] == a[i][2]){
                d[t][0]++;
            }
            else{
                d[t][1]++;
            }
            t = 1 - t;
        }
        cout<< min(d[1 - t][0], d[1 - t][1]);
        return 0;
    }
    for(i = 1; i <= n; i++){
        for(ii = 0; ii < 8; ii++){
            d[t][ii] = 3 * n;
            for(jj = 0; jj < 8; jj++){
                if(verif(ii / 2, jj / 2) && verif(ii % 4, jj % 4) ){
                    d[t][ii] = min(d[t][ii], d[1 - t][jj] + calc(i, ii) );
                }
            }
        }
        t = 1 - t;
    }
    sol = 3 * n;
    for(ii = 0; ii < 8; ii++){
        sol = min(sol, d[1 - t][ii]);
    }
    cout<< sol;
}