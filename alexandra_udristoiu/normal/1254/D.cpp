#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
#define mod 998244353
#define DIM 150005
using namespace std;
int n, q, i, x, y, t, nr, r, ii, nod, val, sol, aux;
int viz[DIM], niv[DIM], frst[DIM], p[DIM], u[DIM], w[DIM], sum[DIM], b[DIM];
int a[18][DIM], aint[4 * DIM];
vector<int> v[DIM];
void dfs(int nod){
    viz[nod] = 1;
    p[nod] = ++nr;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            niv[vecin] = niv[nod] + 1;
            a[0][vecin] = nod;
            dfs(vecin);
        }
    }
    u[nod] = nr;
}
int ancest(int nod, int nr){
    while(nr > 0){
        nod = a[ b[nr] ][nod];
        nr -= (1 << b[nr]);
    }
    return nod;
}
int mult(int x, int e){
    if(e == 0){
        return 1;
    }
    else{
        int a = mult(x, e / 2);
        if(e % 2 == 0){
            return a * 1LL * a % mod;
        }
        else{
            return a * 1LL * a % mod * x % mod;
        }
    }
}
int modul(int x){
    if(x >= mod){
        return x - mod;
    }
    return x;
}
void update(int nod, int st, int dr, int p, int u, int val){
    if(p <= st && dr <= u){
        aint[nod] = modul(aint[nod] + val);
    }
    else{
        int mid = (st + dr) / 2;
        if(p <= mid){
            update(2 * nod, st, mid, p, u, val);
        }
        if(u > mid){
            update(2 * nod + 1, mid + 1, dr, p, u, val);
        }
    }
}
void query(int nod, int st, int dr, int p){
    sol = modul(sol + aint[nod]);
    if(st != dr){
        int mid = (st + dr) / 2;
        if(p <= mid){
            query(2 * nod, st, mid, p);
        }
        else{
            query(2 * nod + 1, mid + 1, dr, p);
        }
    }
}
int main(){
    scanf("%d%d", &n, &q);
    for(i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for(ii = 1; (1 << ii) <= n; ii++){
        for(i = 1; i <= n; i++){
            if(a[ii - 1][i] != 0){
                a[ii][i] = a[ii - 1][ a[ii - 1][i] ];
            }
        }
    }
    for(i = 2; i <= n; i++){
        b[i] = 1 + b[i / 2];
    }
    r = sqrt(n * 1.0);
    r = 200;
    nr = 0;
    val = mult(n, mod - 2);
    for(i = 1; i <= n; i++){
        if(v[i].size() > r){
            w[++nr] = i;
        }
    }
    for(; q; q--){
        scanf("%d%d", &t, &x);
        if(t == 1){
            scanf("%d", &y);
            aint[1] = (aint[1] + y * 1LL * (u[x] - p[x] + 1) ) % mod;
            aux = y * 1LL * (n - u[x] + p[x] - 1) % mod;
            update(1, 1, n, p[x], u[x], aux);
            if(v[x].size() <= r){
                for(i = 0; i < v[x].size(); i++){
                    nod = v[x][i];
                    if(niv[nod] > niv[x]){
                        aux = (mod - y * 1LL * (u[nod] - p[nod] + 1) % mod ) % mod;
                        update(1, 1, n, p[nod], u[nod], aux);
                    }
                }
            }
            else{
                sum[x] = (sum[x] + y) % mod;
            }
            continue;
        }
        sol = 0;
        query(1, 1, n, p[x]);
        for(i = 1; i <= nr; i++){
            y = w[i];
            if(p[y] < p[x] && u[x] <= u[y]){
                nod = ancest(x, niv[x] - niv[y] - 1);
                aux = sum[y] * 1LL * (u[nod] - p[nod] + 1) % mod;
                sol -= aux;
                if(sol < 0){
                    sol += mod;
                }
            }
        }
        sol = sol * 1LL * val % mod;
        printf("%d\n", sol);
    }
}