#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+10,M=3e6;

ll from[M],to[M],cap[M],ptr[N],head[N],prv[M],ecnt=0,dis[N];

void add_edge(ll v,ll u,ll ca){
    from[ecnt]=v,to[ecnt]=u,cap[ecnt]=ca,prv[ecnt]=head[v],head[v]=ecnt++;
    from[ecnt]=u,to[ecnt]=v,cap[ecnt]=0,prv[ecnt]=head[u],head[u]=ecnt++;
}
bool bfs(ll source,ll sink){
    memset(dis,63,sizeof dis);
    dis[source]=0;
    queue <int> q;
    q.push(source);
    while(q.size()){
        ll v=q.front();
     //   cout << v << endl;
        q.pop();
        if (v==sink) return 1;
        for (auto yal=head[v];yal>-1;yal=prv[yal]){
            ll u=to[yal];
            if (cap[yal]==0) continue;
            if (dis[u]>dis[v]+1){
                dis[u]=dis[v]+1;
                q.push(u);
            }
        }
    }
    return 0;
}
ll dfs(ll v,ll sink,ll f){
    if (sink==v || f==0) return f;
    ll ans=0;
    for (auto &yal=ptr[v];yal>-1;yal=prv[yal]){
        ll u=to[yal];
        if (cap[yal]==0 || dis[u]!=dis[v]+1) continue;
        ll z=dfs(u,sink,min(f,cap[yal]));
        f-=z;
        ans+=z;
        cap[yal]-=z;
        cap[yal ^ 1]+=z;
        if (f==0) break;
    }
    return ans;
}
ll maxflow(ll source,ll sink){
    ll ans=0;
    while(bfs(source,sink)){
        for (int i=0;i<N;i++) ptr[i]=head[i];
        ans+=dfs(source,sink,(ll)1e18);
      //  cout << ans << endl;
    }
    return ans;
}
ll mark[N];
ll visvis[M];
vector <pair <int,pii>> ras;
vector <pii> g[N];
void tour(ll v){
    while(g[v].size()){
        ll i=g[v].back().F;
        if (mark[i]==0){
            ll u=g[v].back().S;
            g[v].pop_back();
            mark[i]=1;
            ras.pb({i,{u,v}});
            tour(u);
            continue;
        }
        g[v].pop_back();
    }
}
ll a[N];
ll s[N];
ll isyal[N];
pii ans[N];
ll in[N];
int32_t main(){
    sync;
    memset(head,-1,sizeof head);
    ll n,m;
    cin >> n >> m;
    vector <pii> yal;
    ll cnt1=0,cnt0=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> s[i];
    for (int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        yal.pb({u,v});
        in[u]++;
        in[v]++;
    }
    for (int i=1;i<=n;i++){
        if (a[i]==0) continue;
        if (s[i]<0){
            visvis[ecnt]=1;
            cnt0-=s[i];
            add_edge(0,i,-s[i]);
        }
        else{
            visvis[ecnt]=1;
            cnt1+=s[i];
            add_edge(i,N-1,s[i]);
        }
    }
    for (int i=0;i<m;i++){
        ll u=yal[i].F,v=yal[i].S;
        isyal[ecnt]=i+1;
        if (a[u]==0 && a[v]==0){
            g[u].pb({i+1,v});
            g[v].pb({i+1,u});
        }
        if (a[u]==0){
            swap(yal[i].F,yal[i].S);
            swap(u,v);
        }
        if (a[v]==0){
            if (s[u]<0){
                add_edge(u,N-1,1);
            }
            else{
                add_edge(0,u,1);
            }
        }
        else{
            add_edge(u,v,1);
            isyal[ecnt]=i+1;
            add_edge(v,u,1);
        }
    }
    ll x=maxflow(0,N-1);
    for (int i=0;i<M;i++){
        if (visvis[i]==1 && cap[i]!=0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i=1;i<=n;i++){
        if (a[i]!=0 && (in[i]+s[i])%2!=0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;  
    for (int i=0;i<ecnt;i+=2){
        ll j=i+2;
        if (isyal[i]==0) continue;
        if (isyal[i]!=0 && isyal[i+2]==isyal[i]){
            if ((cap[i]+cap[i+2])%2==0){
                ll u=yal[isyal[i]-1].F;
                ll v=yal[isyal[i]-1].S;
                g[u].pb({isyal[i],v});
                g[v].pb({isyal[i],u});
            }
            else{
                if (cap[i]==1) i+=2;
                ll u=from[i];
                ll v=to[i];
                ans[isyal[i]]={u,v};
            }
            i=j;
        }
        else {
            ll u=from[i];
            ll v=to[i];
            if (u==0){
                u=yal[isyal[i]-1].F+yal[isyal[i]-1].S-v;
            }
            if (v==0){
                v=yal[isyal[i]-1].F+yal[isyal[i]-1].S-u;
            }
            //cout << isyal[i] <<  " kerng " << from[i] << " " << to[i] << endl;
            if (cap[i]==0){
                ans[isyal[i]]={u,v};
            }
            else{
                g[u].pb({isyal[i],v});
                g[v].pb({isyal[i],u});
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (g[i].size()%2==1){
            g[0].pb({N-1,i});
            g[i].pb({N-1,0});
        }
    }
    for (int i=1;i<=n;i++){
        if (g[i].size()){
            tour(i);
        }
    }
    for (int i=0;i<ras.size();i++){
        if (ras[i].F<=m){
            ans[ras[i].F]=ras[i].S;
        }
    }
    for (int i=1;i<=m;i++){
        cout << ans[i].F << " " << ans[i].S << endl;
    }




}