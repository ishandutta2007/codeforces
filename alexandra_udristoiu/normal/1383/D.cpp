#include<iostream>
#define DIM 250 * 250 + 5
using namespace std;
int n, m, i, j, maxim, ii, jj, nr, k;
int a[255][255], lin[DIM], col[DIM], viz[255][255];
pair<int, int> p[DIM];
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        maxim = 0;
        for(j = 1; j <= m; j++){
            cin>> a[i][j];
            maxim = max(maxim, a[i][j]);
        }
        lin[maxim] = 1;
    }
    for(j = 1; j <= m; j++){
        maxim = 0;
        for(i = 1; i <= n; i++){
            maxim = max(maxim, a[i][j]);
        }
        col[maxim] = 1;
    }
    ii = n + 1;
    jj = m + 1;
    for(k = n * m; k >= 1; k--){
        if(lin[k] + col[k] == 0){
            continue;
        }
        ii -= lin[k];
        jj -= col[k];
        a[ii][jj] = k;
        viz[ii][jj] = 1;
        for(i = ii + 1; i <= n; i++){
            if(viz[i][jj] == 0){
                p[++nr] = make_pair(i, jj);
                viz[i][jj] = 1;
            }
        }
        for(j = jj + 1; j <= m; j++){
            if(viz[ii][j] == 0){
                p[++nr] = make_pair(ii, j);
                viz[ii][j] = 1;
            }
        }
    }
    nr = 1;
    for(k = n * m; k >= 1; k--){
        if(lin[k] + col[k] == 0){
            a[ p[nr].first ][ p[nr].second ] = k;
            nr++;
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cout<< a[i][j] <<" ";
        }
        cout<<"\n";
    }
}