#include<iostream>
#include<cstdio>
#define f first
#define s second
#define DIM 300005
using namespace std;
int n, i, m, x;
int p[DIM], q[DIM];
pair<int, int> aint[4 * DIM];
void update(int nod, int st, int dr, int p, int val){
    if(st == dr){
        aint[nod].f += val;
        aint[nod].s = aint[nod].f;
    }
    else{
        int mid = (st + dr) / 2;
        if(p <= mid){
            update(2 * nod, st, mid, p, val);
        }
        else{
            update(2 * nod + 1, mid + 1, dr, p, val);
        }
        aint[nod].f = max(aint[2 * nod].f, aint[2 * nod].s + aint[2 * nod + 1].f);
        aint[nod].s = aint[2 * nod].s + aint[2 * nod + 1].s;
    }
}
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &x);
        p[x] = i;
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &q[i]);
    }
    m = n;
    update(1, 1, n, n - p[m] + 1, 1);
    cout<< m <<" ";
    for(i = 1; i < n; i++){
        update(1, 1, n, n - q[i] + 1, -1);
        while(aint[1].f <= 0){
            m--;
            update(1, 1, n, n - p[m] + 1, 1);
        }
        cout<< m <<" ";
    }
}