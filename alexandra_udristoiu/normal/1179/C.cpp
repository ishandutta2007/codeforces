#include<iostream>
#include<cstdio>
#define DIM 300005
#define f first
#define s second
using namespace std;
int n, m, k, i, q, t, p, x;
int a[DIM], b[DIM];
pair<int, int> aint[4000005];
void update(int nod, int st, int dr, int p, int x){
    if(st == dr){
        aint[nod].f += x;
        aint[nod].s += x;
    }
    else{
        int mid = (st + dr) / 2;
        if(p <= mid){
            update(2 * nod, st, mid, p, x);
        }
        else{
            update(2 * nod + 1, mid + 1, dr, p, x);
        }
        aint[nod].s = aint[2 * nod].s + aint[2 * nod + 1].s;
        aint[nod].f = max(aint[2 * nod].f, aint[2 * nod].s + aint[2 * nod + 1].f);
    }
}
int query(int nod, int st, int dr, int sum){
    if(st == dr){
        return st;
    }
    else{
        int mid = (st + dr) / 2;
        if(sum + aint[2 * nod].f > 0){
            return query(2 * nod, st, mid, sum);
        }
        else{
            return query(2 * nod + 1, mid + 1, dr, sum + aint[2 * nod].s);
        }
    }
}
int main(){
    k = 1000000;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        update(1, 1, k, k - a[i] + 1, 1);
    }
    for(i = 1; i <= m; i++){
        scanf("%d", &b[i]);
        update(1, 1, k, k - b[i] + 1, -1);
    }
    scanf("%d", &q);
    for(; q; q--){
        scanf("%d%d%d", &t, &p, &x);
        if(t == 1){
            update(1, 1, k, k - a[p] + 1, -1);
            a[p] = x;
            update(1, 1, k, k - a[p] + 1, 1);
        }
        else{
            update(1, 1, k, k - b[p] + 1, 1);
            b[p] = x;
            update(1, 1, k, k - b[p] + 1, -1);
        }
        if(aint[1].f <= 0){
            printf("-1\n");
        }
        else{
            x = query(1, 1, k, 0);
            printf("%d\n", k - x + 1);
        }
    }
}