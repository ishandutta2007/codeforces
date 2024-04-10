#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, x, q, t, y, nr, ii;
int a[19][2 * DIM], b[2 * DIM], frst[DIM], p[DIM], niv[DIM], p2[DIM];
vector<int> v[DIM];
struct str{
    int x, y;
};
str aint[4 * DIM], c;
void dfs(int nod){
    a[0][++nr] = nod;
    frst[nod] = nr;
    for(int i = 0; i < v[nod].size(); i++){
        niv[ v[nod][i] ] = niv[nod] + 1;
        dfs(v[nod][i]);
        a[0][++nr] = nod;
    }
}
int lca(int x, int y){
    x = frst[x];
    y = frst[y];
    if(x > y){
        swap(x, y);
    }
    int p = b[y - x];
    if(niv[ a[p][x] ] < niv[ a[p][y - (1 << p) + 1] ]){
        return a[p][x];
    }
    else{
        return a[p][y - (1 << p) + 1];
    }
}
int dist(int x, int y){
    return niv[x] + niv[y] - niv[ lca(x, y) ] * 2;
}
void solve(str &nod, str fiu1, str fiu2){
    if(fiu1.x == -1 || fiu2.x == -1){
        nod.x = -1;
        return;
    }
    nod = fiu1;
    if(dist(nod.x, fiu2.x) == dist(nod.x, nod.y) + dist(nod.y, fiu2.x) ){
        nod.y = fiu2.x;
    }
    else{
        if(dist(nod.y, fiu2.x) == dist(nod.y, nod.x) + dist(nod.x, fiu2.x)){
            nod.x = fiu2.x;
        }
        else{
            if(dist(nod.x, nod.y) != dist(nod.x, fiu2.x) + dist(nod.y, fiu2.x) ){
                nod.x = -1;
                return;
            }
        }
    }
    if(dist(nod.x, fiu2.y) == dist(nod.x, nod.y) + dist(nod.y, fiu2.y) ){
        nod.y = fiu2.y;
    }
    else{
        if(dist(nod.y, fiu2.y) == dist(nod.y, nod.x) + dist(nod.x, fiu2.y)){
            nod.x = fiu2.y;
        }
        else{
            if(dist(nod.x, nod.y) != dist(nod.x, fiu2.y) + dist(nod.y, fiu2.y) ){
                nod.x = -1;
                return;
            }
        }
    }
}
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod].x = aint[nod].y = p[st];
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        solve(aint[nod], aint[2 * nod], aint[2 * nod + 1]);
    }
}
void update(int nod, int st, int dr, int p, int x){
    if(st == dr){
        aint[nod].x = aint[nod].y = x;
    }
    else{
        int mid = (st + dr) / 2;
        if(p <= mid){
            update(2 * nod, st, mid, p, x);
        }
        else{
            update(2 * nod + 1, mid + 1, dr, p, x);
        }
        solve(aint[nod], aint[2 * nod], aint[2 * nod + 1]);
    }
}
int query(int nod, int st, int dr){
    if(st == dr){
        return st;
    }
    else{
        int mid = (st + dr) / 2;
        str aux = c;
        if(c.x == 0){
            c = aint[2 * nod];
        }
        else{
            solve(c, c, aint[2 * nod]);
        }
        if(c.x == -1){
            c = aux;
            return query(2 * nod, st, mid);
        }
        return query(2 * nod + 1, mid + 1, dr);
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        p[x + 1] = i;
        p2[i] = x + 1;
    }
    for(i = 2; i <= n; i++){
        cin>> x;
        v[x].push_back(i);
    }
    dfs(1);
    for(ii = 1; (1 << ii) <= nr; ii++){
        for(i = 1; i <= nr - (1 << ii) + 1; i++){
            a[ii][i] = a[ii - 1][i + (1 << (ii - 1) ) ];
            if(niv[ a[ii][i] ] > niv[ a[ii - 1][i] ]){
                a[ii][i] = a[ii - 1][i];
            }
        }
    }
    for(i = 2; i <= nr; i++){
        b[i] = b[i / 2] + 1;
    }
    build(1, 1, n);
    cin>> q;
    for(; q; q--){
        cin>> t;
        if(t == 2){
            if(aint[1].x != -1){
                cout<< n <<"\n";
                continue;
            }
            c = {0, 0};
            cout<< query(1, 1, n) - 1 <<"\n";
            continue;
        }
        cin>> x >> y;
        swap(p2[x], p2[y]);
        update(1, 1, n, p2[x], x);
        update(1, 1, n, p2[y], y);
    }
    return 0;
}