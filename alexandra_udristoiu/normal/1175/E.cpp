#include<iostream>
#include<algorithm>
#include<vector>
#define DIM 500005
#define x first
#define y second
using namespace std;
int n, m, q, i, x, y, u, maxim;
int ff[DIM], sol[DIM], aint[4 * DIM], viz[DIM];
pair<int, int> v[DIM];
vector<int> vv[DIM];
vector< pair<int, int> > w[DIM];
void update(int nod, int st, int dr, int p, int u, int val){
    if(p <= st && dr <= u){
        aint[nod] += val;
    }
    else{
        aint[2 * nod] += aint[nod];
        aint[2 * nod + 1] += aint[nod];
        aint[nod] = 0;
        int mid = (st + dr) / 2;
        if(p <= mid){
            update(2 * nod, st, mid, p, u, val);
        }
        if(u > mid){
            update(2 * nod + 1, mid + 1, dr, p, u, val);
        }
    }
}
int query(int nod, int st, int dr, int p){
    if(st == dr){
        return aint[nod];
    }
    else{
        aint[2 * nod] += aint[nod];
        aint[2 * nod + 1] += aint[nod];
        aint[nod] = 0;
        int mid = (st + dr) / 2;
        if(p <= mid){
            return aint[nod] + query(2 * nod, st, mid, p);
        }
        else{
            return aint[nod] + query(2 * nod + 1, mid + 1, dr, p);
        }
    }
}
void dfs(int nod, int p){
    viz[nod] = 1;
    update(1, 1, m, nod + 1, p, 1);
    for(int i = 0; i < w[nod].size(); i++){
        sol[ w[nod][i].y ] = query(1, 1, m, w[nod][i].x);
        if(sol[ w[nod][i].y ] == 0){
            sol[ w[nod][i].y ] = -1;
        }
    }
    for(int i = 0; i < vv[nod].size(); i++){
        dfs(vv[nod][i], p);
    }
    update(1, 1, m, nod + 1, p, -1);
}
int main(){
    cin>> n >> q;
    m = 500000;
    for(i = 1; i <= n; i++){
        cin>> v[i].x >> v[i].y;
    }
    sort(v + 1, v + n + 1);
    u = 1;
    for(i = 0; i <= m; i++){
        while(u <= n && v[u].x == i){
            maxim = max(maxim, v[u].y);
            u++;
        }
        if(maxim > i){
            vv[maxim].push_back(i);
            ff[i] = maxim;
        }
    }
    for(i = 1; i <= q; i++){
        cin>> x >> y;
        w[x].push_back( make_pair(y, i) );
        sol[i] = -1;
    }
    for(i = m; i >= 0; i--){
        if(viz[i] == 0 && ff[i] != 0){
            dfs(i, ff[i]);
        }
    }
    for(i = 1; i <= q; i++){
        cout<< sol[i] <<"\n";
    }
}