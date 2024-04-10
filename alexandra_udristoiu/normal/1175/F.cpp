#include<iostream>
#define DIM 300005
using namespace std;
int n, i, nr, j, st, dr, sol, maxim;
int v[DIM], p[DIM], nxt[DIM], aint[4 * DIM], ff[DIM];
long long sum[DIM], s[DIM];
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod] = nxt[st];
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        aint[nod] = min(aint[2 * nod], aint[2 * nod + 1]);
    }
}
int query(int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        return aint[nod];
    }
    else{
        int mid = (st + dr) / 2;
        int x = n + 1, y = n + 1;
        if(p <= mid){
            x = query(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            y = query(2 * nod + 1, mid + 1, dr, p, u);
        }
        x = min(x, y);
        return x;
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        sum[i] = sum[i - 1] + v[i];
        if(v[i] == 1){
            p[++nr] = i;
        }
    }
    for(i = 1; i <= n; i++){
        ff[i] = n + 1;
        s[i] = i + s[i - 1];
    }
    for(i = n; i >= 1; i--){
        nxt[i] = ff[ v[i] ];
        ff[ v[i] ] = i;
    }
    build(1, 1, n);
    p[nr + 1] = n + 1;
    for(i = 1; i <= nr; i++){
        maxim = 0;
        sol++;
        for(j = p[i] + 1; j < p[i + 1]; j++){
            maxim = max(maxim, v[j]);
            dr = j;
            st = j - maxim + 1;
            if(query(1, 1, n, st, dr) > dr && sum[dr] - sum[st - 1] == s[maxim]){
                sol++;
            }
        }
        maxim = 0;
        for(j = p[i] - 1; j > p[i - 1]; j--){
            maxim = max(maxim, v[j]);
            st = j;
            dr = j + maxim - 1;
            if(query(1, 1, n, st, dr) > dr && sum[dr] - sum[st - 1] == s[maxim]){
                sol++;
            }
        }
    }
    cout<< sol;
}