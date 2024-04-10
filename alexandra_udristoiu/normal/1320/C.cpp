#include<iostream>
#include<cstdio>
#include<algorithm>
#define DIM 1000005
#define f first
#define s second
using namespace std;
int n, m, p, k, i, u;
long long sol;
pair<int, int> a[DIM], b[DIM];
pair<long long, long long> aint[4 * DIM];
long long aux[DIM];
struct str{
    int x, y, c;
};
str v[DIM];
int cmp(str a, str b){
    return a.x < b.x;
}
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod].f = aux[st];
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        aint[nod].f = max(aint[2 * nod].f, aint[2 * nod + 1].f);
    }
}
void update(int nod, int st, int dr, int p, int u, int val){
    if(p <= st && dr <= u){
        aint[nod].s += val;
    }
    else{
        int mid = (st + dr) / 2;
        aint[2 * nod].s += aint[nod].s;
        aint[2 * nod + 1].s += aint[nod].s;
        aint[nod].s = 0;
        if(p <= mid){
            update(2 * nod, st, mid, p, u, val);
        }
        if(u > mid){
            update(2 * nod + 1, mid + 1, dr, p, u, val);
        }
        aint[nod].f = max(aint[2 * nod].f + aint[2 * nod].s, aint[2 * nod + 1].f + aint[2 * nod + 1].s);
    }
}
int main(){
    cin>> n >> m >> p;
    for(i = 1; i <= n; i++){
        scanf("%d%d", &a[i].f, &a[i].s);
    }
    for(i = 1; i <= m; i++){
        scanf("%d%d", &b[i].f, &b[i].s);
        k = max(k, b[i].f + 1);
    }
    for(i = 1; i <= p; i++){
        cin>> v[i].x >> v[i].y >> v[i].c;
        k = max(k, v[i].y + 1);
    }
    for(i = 1; i <= k; i++){
        aux[i] = -1000000000000000LL;
    }
    for(i = 1; i <= m; i++){
        aux[ b[i].f ] = max(aux[ b[i].f ], -b[i].s * 1LL);
    }
    build(1, 1, k);
    sol = -1000000000000000LL;
    sort(a + 1, a + n + 1);
    sort(v + 1, v + p + 1, cmp);
    u = 1;
    for(i = 1; i <= n; i++){
        while(u <= p && a[i].f > v[u].x){
            update(1, 1, k, v[u].y + 1, k, v[u].c);
            u++;
        }
        sol = max(sol, - a[i].s + aint[1].f + aint[1].s);
    }
    cout<< sol;
}