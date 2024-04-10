#include<iostream>
#define DIM 100005
using namespace std;
int n, m, i, ok;
int aint[4 * DIM], v[DIM];
struct queries{
    int p, u, val;
};
queries w[DIM];
void solve(int nod, int st, int dr){
    if(st == dr){
        v[st] = aint[nod];
    }
    else{
        int mid = (st + dr) / 2;
        aint[2 * nod] |= aint[nod];
        aint[2 * nod + 1] |= aint[nod];
        solve(2 * nod, st, mid);
        solve(2 * nod + 1, mid + 1, dr);
        aint[nod] = (aint[2 * nod] & aint[2 * nod + 1]);
    }
}
void update(int nod, int st, int dr, int p, int u, int val){
    if(p <= st && dr <= u){
        aint[nod] |= val;
    }
    else{
        int mid = (st + dr) / 2;
        if(p <= mid){
            update(2 * nod, st, mid, p, u, val);
        }
        if(u > mid){
            update(2 * nod + 1, mid + 1, dr, p, u, val);
        }
    }
}
int query(int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        return aint[nod];
    }
    else{
        int mid = (st + dr) / 2;
        int x, y;
        x = y = (1 << 30) - 1;
        if(p <= mid){
            x = query(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            y = query(2 * nod + 1, mid + 1, dr, p, u);
        }
        return (x & y);
    }
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> w[i].p >> w[i].u >> w[i].val;
        update(1, 1, n, w[i].p, w[i].u, w[i].val);
    }
    solve(1, 1, n);
    ok = 1;
    for(i = 1; i <= m; i++){
        if(query(1, 1, n, w[i].p, w[i].u) != w[i].val){
            ok = 0;
            break;
        }
    }
    if(ok == 1){
        cout<<"YES\n";
        for(i = 1; i <= n; i++){
            cout<< v[i] <<" ";
        }
    }
    else{
        cout<<"NO\n";
    }
}