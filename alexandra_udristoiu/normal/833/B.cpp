#include<iostream>
#define DIM 35005
#define f first
#define s second
using namespace std;
int n, k, i, ii;
int v[DIM], lst[DIM], ff[DIM], d[52][DIM];
pair<int, int> aint[4 * DIM];
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod].f = d[ii - 1][st];
        aint[nod].s = 0;
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        aint[nod].f = max(aint[2 * nod].f, aint[2 * nod + 1].f);
        aint[nod].s = 0;
    }
}
void update(int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        aint[nod].s++;
    }
    else{
        int mid = (st + dr) / 2;
        aint[2 * nod].s += aint[nod].s;
        aint[2 * nod + 1].s += aint[nod].s;
        aint[nod].s = 0;
        if(p <= mid){
            update(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            update(2 * nod + 1, mid + 1, dr, p, u);
        }
        aint[nod].f = max(aint[2 * nod].f + aint[2 * nod].s, aint[2 * nod + 1].f + aint[2 * nod + 1].s);
    }
}
int query(int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        return aint[nod].f + aint[nod].s;
    }
    else{
        int mid = (st + dr) / 2;
        int a = 0, b = 0;
        aint[2 * nod].s += aint[nod].s;
        aint[2 * nod + 1].s += aint[nod].s;
        aint[nod].s = 0;
        if(p <= mid){
            a = query(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            b = query(2 * nod + 1, mid + 1, dr, p, u);
        }
        return max(a, b);
    }
}
int main(){
    cin>> n >> k;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= n; i++){
        d[1][i] = d[1][i - 1];
        if(ff[ v[i] ] == 0){
            d[1][i]++;
            lst[i] = 1;
        }
        else{
            lst[i] = ff[ v[i] ];
        }
        ff[ v[i] ] = i;
    }
    for(ii = 2; ii <= k; ii++){
        build(1, 1, n);
        for(i = ii; i <= n; i++){
            update(1, 1, n, lst[i], i - 1);
            d[ii][i] = query(1, 1, n, 1, i - 1);
        }
    }
    cout<< d[k][n];
    return 0;
}