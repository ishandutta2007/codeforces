#include <bits/stdc++.h>

using namespace :: std;

#define F first
#define S second
#define pb push_back

const long long INF=1e9+10,MAX=2e5+1e4,MOD=1e9+7,MAXL=25;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;

void OUT(long double o,int x){
  cout<<fixed<<setprecision(x)<<o;
  return;
}

ll a[MAX],s[MAX],b[MAX],dp[MAXL][MAX],st[MAX],en[MAX],h[MAX],ti=0,seg[4*MAX],lazy[4*MAX];

vector<int> adj[MAX];

void shift(int id,int b,int e){
 ll m=(b+e)/2;
 seg[id*2]+=(m-b)*lazy[id];
 seg[id*2+1]+=(e-m)*lazy[id];
 lazy[id*2]+=lazy[id];
 lazy[id*2+1]+=lazy[id];
 lazy[id]=0;
}

void upd(int id,int b,int e,int l,int r,ll x){
 if(e<=l||r<=b) return;
 if(l<=b&&e<=r){
  seg[id]+=(e-b)*x;
  lazy[id]+=x;
  return;
 }
 int m=(b+e)/2;
 shift(id,b,e);
 upd(id*2,b,m,l,r,x);
 upd(id*2+1,m,e,l,r,x);
 seg[id]=seg[id*2]+seg[id*2+1];
}

ll geta(int id,int b,int e,int l,int r){
 if(e<=l||r<=b) return 0;
 if(l<=b&&e<=r) return seg[id];
 int m=(b+e)/2;
 shift(id,b,e);
 return geta(id*2,b,m,l,r)+geta(id*2+1,m,e,l,r);
}

void dfs(int v,int p){
 h[v]=h[p]+1;
 dp[0][v]=p;
 s[v]=a[v];
 st[v]=++ti;
 b[v]=1;
 for(int i=1;i<=20;i++)
  dp[i][v]=dp[i-1][dp[i-1][v]];
 for(int u:adj[v])
  if(u!=p){
   dfs(u,v);
   s[v]+=s[u];
   b[v]+=b[u];
  }
 en[v]=ti;
}

ll g(int v,int x){
 for(int i=0;i<=20;i++)
  if(x&(1<<i))
   v=dp[i][v];
 return v;
}

ll lca(int v,int u){
 if(h[u]<h[v])
  swap(v,u);
 u=g(u,h[u]-h[v]);
 if(u==v)
  return u;
 for(int i=20;i>=0;i--)
  if(dp[i][v]!=dp[i][u]){
   v=dp[i][v];
   u=dp[i][u];
  }
 return dp[0][v];
}

int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 ll n,q;
 cin>>n>>q;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<n;i++){
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
 }
 dfs(1,1);
 for(int i=1;i<=n;i++)
  upd(1,1,n+1,st[i],st[i]+1,a[i]);
 ll r=1;
 while(q--){
  ll t,v,u,x;
  cin>>t;
  if(t==1){
   cin>>v;
   r=v; 
  }
  if(t==2){
   cin>>u>>v>>x;
   ll uv=lca(u,v),ur=lca(u,r),vr=lca(v,r);
   pii p1={h[uv],uv},p2={h[vr],vr},p3={h[ur],ur};
   pii z=max(p1,max(p2,p3));
   if(st[z.S]<st[r]&&st[r]<=en[z.S]){
    ll y=g(r,h[r]-h[z.S]-1);
    upd(1,1,n+1,1,n+1,x);
    upd(1,1,n+1,st[y],en[y]+1,-x);
   }
   else if(r==z.S)
    upd(1,1,n+1,1,n+1,x);
   else
    upd(1,1,n+1,st[z.S],en[z.S]+1,x);
  }
  if(t==3){
   cin>>v;
   if(st[v]<st[r]&&st[r]<=en[v]){
    ll y=g(r,h[r]-h[v]-1);
    cout<<geta(1,1,n+1,1,n+1)-geta(1,1,n+1,st[y],en[y]+1)<<"\n";
   }
   else if(r==v)
    cout<<geta(1,1,n+1,1,n+1)<<"\n";
   else
    cout<<geta(1,1,n+1,st[v],en[v]+1)<<"\n";
  }
 }
}