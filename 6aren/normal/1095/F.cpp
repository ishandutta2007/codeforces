#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200000+5;
const int MOD=998244353;

struct edge{
    int u, v;
    ll val;
};

ll n, a[N], m, p[N];
edge e[2*N];

bool cmp(edge a, edge b){
    return a.val < b.val;
}

int get(int u){
    return (p[u]==u) ? u : (p[u]=get(p[u]));
}

ll unite(edge a){
    int u=get(a.u);
    int v=get(a.v);
    if (u!=v){
        p[u]=v;
        return a.val;
    } else return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int mmr=1;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (a[i]<a[mmr]) mmr=i;
    }
    int id=0;
    for (int i=1; i<=n; i++){
        if (i==mmr) continue;
        e[id].u=mmr;
        e[id].v=i;
        e[id].val=a[mmr]+a[i];
        id++;
    }
    for (int i=1; i<=m; i++){
        ll u, v, val;
        cin >> u >> v >> val;
        e[id].u=u;
        e[id].v=v;
        e[id].val=val;
        id++;
    }
    sort(e, e+id, cmp);
    ll res=0;
    for (int i=1; i<=n; i++) p[i]=i;
    for (int i=0; i<id; i++){
        res+=unite(e[i]);
    }
    cout << res;
    return 0;
}