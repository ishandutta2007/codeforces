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
const int N=5e6+10;
int n,nex[N];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>nex[i];
}

vi G[N];
int sl=0,it[N];

void build(int id,int l,int r)
{
    if (l==r)
    {
        it[id]=l;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    it[id]=++sl;
    G[sl].eb(it[id*2]);
    G[sl].eb(it[id*2+1]);
}

void upd(int id,int l,int r,int u,int v,int x)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        G[x].eb(it[id]);
        return;
    }
    int mid=(l+r)/2;
    upd(id*2,l,mid,u,v,x);
    upd(id*2+1,mid+1,r,u,v,x);
}

vi vt;
int vis[N],check;

void dfs(int u)
{
    vis[u]=1;
    for (int v : G[u])
        if (vis[v]==1)
        {
            check=0;
            return;
        }
        else if (vis[v]==0)
        {
            dfs(v);
            if (check==0) return;
        }
    vis[u]=2;
    if (u<=n) vt.eb(u);
}

int ans[N];

void process()
{
    for (int i=1;i<=sl;i++) G[i].clear(),vis[i]=0;
    sl=n;
    build(1,1,n);
    for (int i=1;i<=n;i++)
        if (nex[i]!=-1)
        {
            if (i+1<=nex[i]-1) upd(1,1,n,i+1,nex[i]-1,i);
            if (nex[i]<=n) upd(1,1,n,i,i,nex[i]);
        }
    check=1;
    vt.clear();
    for (int i=1;i<=sl;i++)
        if (!vis[i])
        {
            dfs(i);
            if (!check)
            {
                cout<<"-1\n";
                return;
            }
        }
    for (int i=1;i<=n;i++) ans[vt[i-1]]=i;
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        read();
        process();
    }
    return 0;
}