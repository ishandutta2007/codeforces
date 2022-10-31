#include<iostream>
#include<vector>
using namespace std;
int n, m, i, x, y, a1, a2, b1, b2, lg1, lg2, sol, j;
int a[3005][3005], c[3005], viz[3005];
vector<int> v[3005];
void bfs(int srs){
    int i, nod, vecin, p, u;
    p = u = 1;
    for(i = 1; i <= n; i++){
        viz[i] = 0;
    }
    viz[srs] = 1;
    c[1] = srs;
    while(p <= u){
        nod = c[p];
        p++;
        for(i = 0; i < v[nod].size(); i++){
            vecin = v[nod][i];
            if(viz[vecin] == 0){
                a[srs][vecin] = 1 + a[srs][nod];
                viz[vecin] = 1;
                c[++u] = vecin;
            }
        }
    }
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>> a1 >> b1 >> lg1;
    cin>> a2 >> b2 >> lg2;
    for(i = 1; i <= n; i++){
        bfs(i);
    }
    if(a[a1][b1] > lg1 || a[a2][b2] > lg2){
        cout<< -1;
        return 0;
    }
    sol = a[a1][b1] + a[a2][b2];
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(a[a1][i] + a[b1][j] + a[i][j] <= lg1 && a[a2][i] + a[b2][j] + a[i][j] <= lg2){
                sol = min(sol, a[a1][i] + a[a2][i] + a[b1][j] + a[b2][j] + a[i][j]);
            }
            if(a[a1][i] + a[b1][j] + a[i][j] <= lg1 && a[a2][j] + a[b2][i] + a[i][j] <= lg2){
                sol = min(sol, a[a1][i] + a[a2][j] + a[b1][j] + a[b2][i] + a[i][j]);
            }
        }
    }
    cout<< m - sol;
}