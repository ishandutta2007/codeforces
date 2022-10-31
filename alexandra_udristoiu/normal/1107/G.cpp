#include<iostream>
#include<algorithm>
#define DIM 300005
#define f first
#define s second
using namespace std;
int n, i, val, st, dr;
int d[DIM], c[DIM], p[DIM], w[DIM];
long long sol;
struct str{
    long long sum, sol, st, dr;
};
str aint[4 * DIM], aux, x;
int cmp(int x, int y){
    return d[x + 1] - d[x] < d[y + 1] - d[y];
}
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod].st = aint[nod].dr = aint[nod].sum = aint[nod].sol = c[st];
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        aint[nod].sum = aint[2 * nod].sum + aint[2 * nod + 1].sum;
        aint[nod].sol = max(aint[2 * nod].dr + aint[2 * nod + 1].st, max(aint[2 * nod].sol, aint[2 * nod + 1].sol) );
        aint[nod].st = max(aint[2 * nod].st, aint[2 * nod].sum + aint[2 * nod + 1].st);
        aint[nod].dr = max(aint[2 * nod + 1].dr, aint[2 * nod].dr + aint[2 * nod + 1].sum);
    }
}
void query(int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        aux.sum = x.sum + aint[nod].sum;
        aux.sol = max(x.dr + aint[nod].st, max(x.sol, aint[nod].sol) );
        aux.st = max(x.st, x.sum + aint[nod].st);
        aux.dr = max(aint[nod].dr, aint[nod].sum + x.dr);
        x = aux;
    }
    else{
        int mid = (st + dr) / 2;
        if(p <= mid){
            query(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            query(2 * nod + 1, mid + 1, dr, p, u);
        }
    }
}
int main(){
    cin>> n >> val;
    for(i = 1; i <= n; i++){
        cin>> d[i] >> c[i];
        c[i] = val - c[i];
        sol = max(sol, c[i] * 1LL);
        w[i] = i;
        p[i] = i;
    }
    sort(w + 1, w + n, cmp);
    build(1, 1, n);
    for(i = 1; i < n; i++){
        st = p[ w[i] ];
        dr = p[ w[i] + 1 ];
        p[st] = dr;
        p[dr] = st;
        x = {0, 0, 0, 0};
        query(1, 1, n, st, dr);
        sol = max(sol, x.sol - (d[ w[i] + 1 ] - d[ w[i] ]) * 1LL * (d[ w[i] + 1 ] - d[ w[i] ]) );
    }
    cout<< sol;
    return 0;
}