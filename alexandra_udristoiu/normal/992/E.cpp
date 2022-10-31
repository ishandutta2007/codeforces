#include<iostream>
#define DIM 200005
#define f first
#define s second
using namespace std;
int n, q, i, x, y, poz, p;
int v[DIM];
pair<long long, int> aint[4 * DIM];
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod].f = aint[nod].s = v[st];
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        aint[nod].f = aint[2 * nod].f + aint[2 * nod + 1].f;
        aint[nod].s = max(aint[2 * nod].s, aint[2 * nod + 1].s);
    }
}
void update(int nod, int st, int dr, int poz){
    if(st == dr){
        aint[nod].f = aint[nod].s = v[st];
    }
    else{
        int mid = (st + dr) / 2;
        if(poz <= mid){
            update(2 * nod, st, mid, poz);
        }
        else{
            update(2 * nod + 1, mid + 1, dr, poz);
        }
        aint[nod].f = aint[2 * nod].f + aint[2 * nod + 1].f;
        aint[nod].s = max(aint[2 * nod].s, aint[2 * nod + 1].s);
    }
}
long long query2(int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        return aint[nod].f;
    }
    else{
        int mid = (st + dr) / 2;
        long long x = 0, y = 0;
        if(p <= mid){
            x = query2(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            y = query2(2 * nod + 1, mid + 1, dr, p, u);
        }
        return x + y;
    }
}
int queryy(int nod, int st, int dr, long long val){
    if(st == dr){
        return st;
    }
    else{
        int mid = (st + dr) / 2;
        if(aint[2 * nod].s >= val){
            return queryy(2 * nod, st, mid, val);
        }
        else{
            return queryy(2 * nod + 1, mid + 1, dr, val);
        }
    }
}
int query(int nod, int st, int dr, int p, long long val){
    if(p <= st){
        if(aint[nod].s < val){
            return -1;
        }
        else{
            return queryy(nod, st, dr, val);
        }
    }
    else{
        int mid = (st + dr) / 2, x = -1;
        if(p <= mid){
            x = query(2 * nod, st, mid, p, val);
        }
        if(x == -1){
            return query(2 * nod + 1, mid + 1, dr, p, val);
        }
        else{
            return x;
        }
    }
}
int main(){
    cin>> n >> q;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    build(1, 1, n);
    for(; q; q--){
        cin>> x >> y;
        v[x] = y;
        update(1, 1, n, x);
        poz = 1;
        if(v[1] == 0){
            cout<<"1\n";
            continue;
        }
        while(poz < n){
            p = query(1, 1, n, poz + 1, query2(1, 1, n, 1, poz) );
            if(p == -1){
                poz = n;
            }
            else{
                if(v[p] == query2(1, 1, n, 1, p - 1) ){
                    cout<< p <<"\n";
                    break;
                }
                poz = p;
            }
        }
        if(poz == n){
            cout<<"-1\n";
        }
    }
    return 0;
}