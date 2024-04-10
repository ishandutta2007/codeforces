#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define fi first 
#define se second 
int n,m;
ll ans[200005];
int par[200005];
struct edge{
    int u,v,w;
};
bool cmp(edge a, edge b){
    return a.w < b.w;
}
edge e[200005];
ii q[200005];
int root(int x){
    return par[x] < 0 ? x : (par[x]=root(par[x]));
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    memset(par, -1, sizeof(par));
    for(int i=1; i<=n-1; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }    
    for(int i=1; i<=m; i++) {
        cin >> q[i].fi;
        q[i].se = i;
    }
 
    sort(e+1, e+n, cmp);
    sort(q+1, q+m+1);
    //cout << 100;
    ll res = 0;
    int pos = 1;
    for(int i=1; i<=m; i++){
        //cout << i << endl;
        while(q[i].fi >= e[pos].w && pos<=n-1) {
            int x = root(e[pos].u), y = root(e[pos].v);
            int k = -par[x];
            int h = -par[y];
            res += 1ll*(h+k)*(h+k-1)/2 - 1ll*h*(h-1)/2 - 1ll*k*(k-1)/2;
            if(par[x] > par[y]) swap(x,y);
            par[x]+=par[y]; par[y]=x;
            pos++;
        }
        ans[q[i].se] = res;
    }
    for(int i=1; i<=m; i++) cout << ans[i] <<" ";
    //freopen("output.txt","w", stdout);
    //fclose(stdout);
    return 0;
}