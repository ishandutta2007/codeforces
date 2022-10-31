#include<iostream>
#define DIM 100005
#define f first
#define s second
using namespace std;
int n, i, q, x, y, st, dr, mid;
char tip;
int k[DIM];
long long s[DIM], ss[DIM], v[DIM];
pair<long long, int> aint[4 * DIM];
long long calc(int p, int u, int x){
    return v[x] * 1LL * (u - p + 1) + ss[u] - ss[p - 1] - s[x] * 1LL * (u - p + 1);
}
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod].f = v[st];
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        aint[nod].f = aint[2 * nod].f + aint[2 * nod + 1].f;
    }
}
void update(int nod, int st, int dr, int p, int u, int x){
    if(p <= st && dr <= u){
        aint[nod].s = x;
        aint[nod].f = calc(st, dr, x);
    }
    else{
        int mid = (st + dr) / 2;
        if(aint[nod].s != 0){
            aint[2 * nod].s = aint[2 * nod + 1].s = aint[nod].s;
            aint[2 * nod].f = calc(st, mid, aint[nod].s);
            aint[2 * nod + 1].f = calc(mid + 1, dr, aint[nod].s);
            aint[nod].s = 0;
        }
        if(p <= mid){
            update(2 * nod, st, mid, p, u, x);
        }
        if(u > mid){
            update(2 * nod + 1, mid + 1, dr, p, u, x);
        }
        aint[nod].f = aint[2 * nod].f + aint[2 * nod + 1].f;
    }
}
long long query(int nod, int st, int dr, int p, int u){
     if(p <= st && dr <= u){
        return aint[nod].f;
    }
    else{
        int mid = (st + dr) / 2;
        if(aint[nod].s != 0){
            aint[2 * nod].s = aint[2 * nod + 1].s = aint[nod].s;
            aint[2 * nod].f = calc(st, mid, aint[nod].s);
            aint[2 * nod + 1].f = calc(mid + 1, dr, aint[nod].s);
            aint[nod].s = 0;
        }
        long long x = 0, y = 0;
        if(p <= mid){
            x = query(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            y = query(2 * nod + 1, mid + 1, dr, p, u);
        }
        aint[nod].f = aint[2 * nod].f + aint[2 * nod + 1].f;
        return x + y;
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 2; i <= n; i++){
        cin>> k[i];
        s[i] = s[i - 1] + k[i];
        ss[i] = ss[i - 1] + s[i];
    }
    build(1, 1, n);
    cin>> q;
    for(; q; q--){
        cin>> tip >> x >> y;
        if(tip == 's'){
            cout<< query(1, 1, n, x, y) <<"\n";
            continue;
        }
        v[x] = query(1, 1, n, x, x) + y;
        st = x;
        dr = n;
        while(st <= dr){
            mid = (st + dr) / 2;
            if( query(1, 1, n, mid, mid) <= v[x] + s[mid] - s[x]){
                st = mid + 1;
            }
            else{
                dr = mid - 1;
            }
        }
        update(1, 1, n, x, dr, x);
        int abc = 0;
    }
}