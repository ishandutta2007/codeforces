#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, x, y, nod, j, ok, m, nr, vecin;
vector<int> vs[DIM], vf[DIM];
int viz[DIM], w[DIM], df[DIM], ds[DIM], p[DIM];
void dfs(int nod){
    viz[nod] = 1;
    for(int i = 0; i < vs[nod].size(); i++){
        if(viz[ vs[nod][i] ] == 0){
            dfs(vs[nod][i]);
        }
    }
    w[++nr] = nod;
    p[nod] = nr;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        vs[x].push_back(y);
        vf[y].push_back(x);
    }
    for(i = 1; i <= n; i++){
        if(vf[i].size() == 0){
            dfs(i);
        }
    }
    if(nr != n){
        cout<< -1;
        return 0;
    }
    for(i = 1; i <= n; i++){
        nod = w[i];
        ds[nod] = nod;
        for(j = 0; j < vs[nod].size(); j++){
            vecin = vs[nod][j];
            if(p[vecin] > p[nod]){
                ok = 1;
            }
            ds[nod] = min(ds[nod], ds[vecin]);
        }
    }
    if(ok == 1){
        cout<< -1;
        return 0;
    }
    for(i = n; i >= 1; i--){
        nod = w[i];
        df[nod] = nod;
        for(j = 0; j < vf[nod].size(); j++){
            vecin = vf[nod][j];
            df[nod] = min(df[nod], df[vecin]);
        }
    }
    nr = 0;
    for(i = 1; i <= n; i++){
        if(df[i] == i && ds[i] == i){
            nr++;
        }
    }
    cout<< nr <<"\n";
    for(i = 1; i <= n; i++){
        if(df[i] == i && ds[i] == i){
            cout<< 'A';
        }
        else{
            cout<< 'E';
        }
    }
}