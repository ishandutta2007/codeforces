#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long lli;

int n,m;
pii a[300001],os[300001],ts[300001];
lli xs[300001],ys[300001];
vector<int> adj[300001];
lli ans[300001];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].fi,&a[i].se);
    for(int i=0,u,v;i<m;i++){
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        os[i]=pii(a[i].fi-a[i].se,i);
        ts[i]=pii(a[i].se-a[i].fi,i);
    }
    sort(os+1,os+n+1);
    sort(ts+1,ts+n+1);

    for(int i=1;i<=n;i++){
        xs[i]=xs[i-1]+a[ts[i].se].fi;
        ys[i]=ys[i-1]+a[ts[i].se].se;
    }

    for(int i=1;i<=n;i++){
        int idx=lower_bound(ts+1,ts+n+1,pii(-os[i].fi,0))-ts-1;
        ans[os[i].se]=ys[idx]+1ll*idx*a[os[i].se].fi + (xs[n]-xs[idx])+1ll*(n-idx)*a[os[i].se].se;
    }

    for(int i=1;i<=n;i++) {
        ans[i] -= a[i].fi+a[i].se;
        for(auto &v:adj[i]){
            ans[i] -= min(a[i].fi+a[v].se,a[i].se+a[v].fi);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",ans[i]);

    return 0;
}