#include<iostream>
#include<vector>
#include<algorithm>
#define DIM 200005
using namespace std;
int n, m, i, a, b, x, y, j, u, t;
long long sol;
int c[2][DIM], nr[2], viz[2][DIM], num[DIM];
vector<int> v[DIM], w[DIM];
int cmp(int a, int b){
    return c[1][a] < c[1][b];
}
void dfs(int t, int nod){
    viz[t][nod] = 1;
    c[t][nod] = nr[t];
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[t][vecin] == 0){
            dfs(t, vecin);
        }
    }
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> m >> a >> b;
        for(i = 1; i <= n; i++){
            v[i].clear();
            w[i].clear();
            viz[0][i] = viz[1][i] = 0;
            num[i] = 0;
        }
        sol = (n - 2) * 1LL * (n - 3);
        for(i = 1; i <= m; i++){
            cin>> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        viz[0][a] = viz[1][b] = 1;
        nr[0] = nr[1] = 0;
        for(i = 1; i <= n; i++){
            if(viz[0][i] == 0){
                nr[0]++;
                dfs(0, i);
            }
            if(viz[1][i] == 0){
                nr[1]++;
                dfs(1, i);
            }
        }
        for(i = 1; i <= n; i++){
            if(i != a && i != b){
                w[ c[0][i] ].push_back(i);
                num[ c[1][i] ]++;
            }
        }
        for(i = 1; i <= nr[1]; i++){
            sol -= num[i] * 1LL * (num[i] - 1);
        }
        for(i = 1; i <= nr[0]; i++){
            sol -= w[i].size() * 1LL * (w[i].size() - 1);
            sort(w[i].begin(), w[i].end(), cmp);
            u = 1;
            for(j = 1; j < w[i].size(); j++){
                if(c[1][ w[i][j] ] != c[1][ w[i][j - 1] ]){
                    sol += u * 1LL * (u - 1);
                    u = 1;
                }
                else{
                    u++;
                }
            }
            sol += u * 1LL * (u - 1);
        }
        cout<< sol / 2 <<"\n";
    }
}