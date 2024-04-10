#include<iostream>
#include<cstdio>
#define DIM 200005
using namespace std;
int n, m, i, st, dr, x, y;
int v[DIM];
char a[4 * DIM][102];
void build(int nod, int st, int dr){
    for(int i = 1; i <= 100; i++){
        a[nod][i] = i;
    }
    if(st != dr){
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
    }
}
void update(int nod, int st, int dr, int p, int u, int x, int y){
    if(p <= st && dr <= u){
        for(int i = 1; i <= 100; i++){
            if(a[nod][i] == x){
                a[nod][i] = y;
            }
        }
    }
    else{
        int mid = (st + dr) / 2, i;
        for(i = 1; i <= 100; i++){
            a[2 * nod][i] = a[nod][ a[2 * nod][i] ];
            a[2 * nod + 1][i] = a[nod][ a[2 * nod + 1][i] ];
        }
        for(i = 1; i <= 100; i++){
            a[nod][i] = i;
        }
        if(p <= mid){
            update(2 * nod, st, mid, p, u, x, y);
        }
        if(u > mid){
            update(2 * nod + 1, mid + 1, dr, p, u, x, y);
        }
    }
}
void solve(int nod, int st, int dr){
    if(st == dr){
        v[st] = a[nod][ v[st] ];
    }
    else{
        int mid = (st + dr) / 2, i;
        for(i = 1; i <= 100; i++){
            a[2 * nod][i] = a[nod][ a[2 * nod][i] ];
            a[2 * nod + 1][i] = a[nod][ a[2 * nod + 1][i] ];
        }
        solve(2 * nod, st, mid);
        solve(2 * nod + 1, mid + 1, dr);
    }
}
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    build(1, 1, n);
    scanf("%d", &m);
    for(; m; m--){
        scanf("%d%d%d%d", &st, &dr, &x, &y);
        update(1, 1, n, st, dr, x, y);
    }
    solve(1, 1, n);
    for(i = 1; i <= n; i++){
        printf("%d ", v[i]);
    }
}