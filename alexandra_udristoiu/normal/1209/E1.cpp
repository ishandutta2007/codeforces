#include<iostream>
#include<algorithm>
using namespace std;
int n, m, t, i, j, sol;
int a[10][105], b[6][6], v[6];
pair<int, int> c[105];
int cmp(pair<int, int> a, pair<int, int> b){
    return a > b;
}
void solve(int p){
    if(p == m + 1){
        int i, j, sum = 0, maxim;
        for(j = 1; j <= m; j++){
            for(i = 1; i <= n; i++){
                b[i][j] = a[ i + v[j] ][ c[j].second ];
            }
        }
        for(i = 1; i <= n; i++){
            maxim = 0;
            for(j = 1; j <= m; j++){
                maxim = max(maxim, b[i][j]);
            }
            sum += maxim;
        }
        sol = max(sol, sum);
    }
    else{
        for(int i = 0; i < n; i++){
            v[p] = i;
            solve(p + 1);
        }
    }
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
        solve(1);
        cout<< sol <<"\n";
    }
}