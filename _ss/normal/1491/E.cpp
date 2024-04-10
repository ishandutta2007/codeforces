#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l,ll r) {return uniform_int_distribution<ll> (l,r)(mt);}
}

using namespace myrand;
const int N=2e5+10;
const ll inf=1e18;
vi G[N];
int n;
ll val[N];

void read()
{
    cin>>n;
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].eb(v);
        G[v].eb(u);
    }
}

int on[N],sz[N],f[N],p[N];

void dfs(int u,int r)
{
    sz[u]=1;
    for (int v : G[u])
        if (v!=r && on[v])
        {
            p[v]=u;
            dfs(v,u);
            sz[u]+=sz[v];
        }
}

void dfs_get(int u,int r,vi &vt)
{
    vt.eb(u);
    on[u]=0;
    for (int v : G[u])
        if (v!=r && on[v]) dfs_get(v,u,vt);
}

unordered_map<ll,bool> ans;

bool check(vi &vt,int d)
{
    if (vt.size()<=3) return true;
    ll sum=0;
    for (int x : vt) sum^=val[x];
    if (ans.count(sum)) return ans[sum];
    for (int x : vt) on[x]=1;
    dfs(vt[0],0);
    int cen=0,cen2=0;
    for (int x : vt)
        if (sz[x]==f[d-1]) cen=x;
        else if (sz[x]==f[d-2]) cen2=x;
    vi vt1,vt2,vt3,vt4;
    if (cen)
    {
        dfs_get(cen,p[cen],vt1);
        for (int x : vt)
            if (on[x]) vt2.eb(x);
            else on[x]=1;
    }
    if (cen2)
    {
        dfs_get(cen2,p[cen2],vt3);
        for (int x : vt)
            if (on[x]) vt4.eb(x);
    }
    for (int x : vt) on[x]=0;
    if (cen && check(vt1,d-1) && check(vt2,d-2)) return (ans[sum]=true);
    if (cen2 && check(vt3,d-2) && check(vt4,d-1)) return (ans[sum]=true);
    return (ans[sum]=false);
}

void process()
{
    for (int i=1;i<=n;i++) val[i]=Int(1,inf);
    ans.max_load_factor(0.25);
    ans.reserve(1<<20);
    f[0]=f[1]=1;
    for (int i=2;i<=27;i++) f[i]=f[i-1]+f[i-2];
    int d=0;
    while (f[d]<n) d++;
    vi vt;
    for (int i=1;i<=n;i++) vt.eb(i);
    if (f[d]==n && check(vt,d)) cout<<"YES";
    else cout<<"NO";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}