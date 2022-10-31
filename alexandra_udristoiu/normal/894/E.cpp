#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#define f first
#define s second
#define DIM 1000005
using namespace std;
int n, m, nr, i, u, srs, k, nod, vecin, cnt, j;
int s[DIM], c[DIM], viz[DIM], niv[DIM], low[DIM], e[DIM], viz2[DIM];
long long d[DIM], val[DIM], sum[DIM], fact[DIM], sol;
struct str{
    int x, y, z;
};
str w[DIM];
vector< pair<int, int> > v[DIM], v2[DIM];
//ifstream fin("date.in");
//ofstream fout("date.out");
void dfs(int nod){
    viz[nod] = 1;
    for(int i = 0; i < v2[nod].size(); i++){
        if(viz[ v2[nod][i].f ] == 0){
            dfs(v2[nod][i].f);
        }
    }
    e[++u] = nod;
}
long long ff(int val){
    int st = 1, dr = k, mid;
    while(st <= dr){
        mid = (st + dr) / 2;
        if(fact[mid] <= val){
            st = mid + 1;
        }
        else{
            dr = mid - 1;
        }
    }
    return val * 1LL * (dr + 1) - sum[dr];
}
void ctc(int nod){
    viz[nod] = viz2[nod] = 1;
    s[++u] = nod;
    cnt++;
    niv[nod] = low[nod] = cnt;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i].f;
        if(viz[vecin] == 0){
            ctc(vecin);
            low[nod] = min(low[nod], low[vecin]);
        }
        else{
            if(viz2[vecin] == 1){
                low[nod] = min(low[nod], low[vecin]);
            }
        }
    }
    if(low[nod] == niv[nod]){
        int x;
        nr++;
        do{
            x = s[u];
            u--;
            c[x] = nr;
            viz2[x] = 0;
        }while(x != nod);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i++){
         scanf("%d%d%d", &w[i].x, &w[i].y, &w[i].z);
        v[ w[i].x ].push_back( make_pair(w[i].y, w[i].z) );
    }
    scanf("%d", &srs);
    for(i = 1; i <= 20000; i++){
        fact[i] = fact[i - 1] + i;
        sum[i] = sum[i - 1] + fact[i];
        if(fact[i] > 100000000){
            k = i;
            break;
        }
    }
    for(i = 1; i <= n; i++){
        if(viz[i] == 0){
            ctc(i);
        }
    }
    for(i = 1; i <= m; i++){
        if(c[ w[i].x ] == c[ w[i].y ]){
            val[ c[ w[i].x ] ] += ff(w[i].z);
        }
        else{
            v2[ c[ w[i].x ] ].push_back(make_pair(c[ w[i].y ], w[i].z) );
        }
    }
    memset(viz, 0, sizeof(viz));
    u = 0;
    dfs(c[srs]);
    for(i = u; i >= 1; i--){
        if(e[i] == c[srs]){
            d[ e[i] ] = val[ e[i] ];
        }
    }
    for(i = u; i >= 1; i--){
        sol = max(sol, d[ e[i] ]);
        nod = e[i];
        for(j = 0; j < v2[nod].size(); j++){
            vecin = v2[nod][j].f;
            d[vecin] = max(d[vecin], d[nod] + val[vecin] + v2[nod][j].s);
        }
    }
    cout<< sol;
    return 0;
}