#include<iostream>
#include<cstdio>
#define DIM 500005
using namespace std;
int n, i, t, ok;
int sol[DIM], v[DIM], aint[4 * DIM];
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod] = st;
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        if(v[ aint[2 * nod] ] >= v[ aint[2 * nod + 1] ]){
            aint[nod] = aint[2 * nod];
        }
        else{
            aint[nod] = aint[2 * nod + 1];
        }
    }
}
int query(int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        return aint[nod];
    }
    else{
        int mid = (st + dr) / 2;
        int x = 0, y = 0;
        if(p <= mid){
            x = query(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            y = query(2 * nod + 1, mid + 1, dr, p, u);
        }
        if(y == 0 || v[x] >= v[y]){
            return x;
        }
        else{
            return y;
        }
    }
}
void solve(int st, int dr, int ad){
    int p = query(1, 1, n, st, dr);
    if(v[p] > dr + 1){
        ok = -1;
        return;
    }
    if(v[p] < dr + 1){
        sol[dr] = ad + dr - st + 1;
        if(st != dr){
            solve(st, dr - 1, ad);
        }
    }
    else{
        sol[p] = ad + dr - st + 1;
        if(p != st){
            solve(st, p - 1, ad);
        }
        if(p != dr){
            solve(p + 1, dr, ad + p - st);
        }
    }
}
int main(){
    scanf("%d", &t);
    for(; t; t--){
        scanf("%d", &n);
        for(i = 1; i <= n; i++){
            scanf("%d", &v[i]);
        }
        build(1, 1, n);
        ok = 0;
        solve(1, n, 0);
        if(ok == -1){
            printf("-1\n");
        }
        else{
            for(i = 1; i <= n; i++){
                printf("%d ", sol[i]);
            }
            printf("\n");
        }
    }
}