#include<iostream>
#include<algorithm>
using namespace std;
int n, m, t, i, j, sol, ii, jj, val, k;
int a[30][2005], b[15][30], d[13][(1 << 12) + 5], sum[15][ (1 << 12) + 5];
pair<int, int> c[2005];
int cmp(pair<int, int> a, pair<int, int> b){
    return a > b;
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> m;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                cin>> a[i][j];
            }
        }
        sol = 0;
        for(j = 1; j <= m; j++){
            c[j] = make_pair(0, j);
            for(i = 1; i <= n; i++){
                c[j].first = max(c[j].first, a[i][j]);
                a[i + n][j] = a[i][j];
            }
        }
        sort(c + 1, c + m + 1, cmp);
        m = min(m, n);
        for(i = 1; i <= m; i++){
            for(j = 1; j <= n + n; j++){
                b[i][j - 1] = a[j][ c[i].second ];
            }
        }
        for(i = 0; i <= m; i++){
            for(j = 0; j < (1 << n); j++){
                d[i][j] = -1000000000;
            }
        }
        d[0][0] = 0;
        for(i = 1; i <= m; i++){
            for(ii = 0; ii < (1 << n); ii++){
                sum[i][ii] = 0;
                for(k = 0; k < n; k++){
                    val = 0;
                    for(j = 0; j < n; j++){
                        if( ( (ii >> j) & 1) == 1){
                            val += b[i][j + k];
                        }
                    }
                    sum[i][ii] = max(sum[i][ii], val);
                }
            }
        }
        for(i = 1; i <= m; i++){
            for(ii = 0; ii < (1 << n); ii++){
                d[i][ii] = d[i - 1][ii];
                for(jj = ii; jj > 0; jj = ( (jj - 1) & ii) ){
                    d[i][ii] = max(d[i][ii], sum[i][jj] + d[i - 1][ii - jj]);
                }
            }
        }
        cout<< d[m][ (1 << n) - 1] <<"\n";
    }
}