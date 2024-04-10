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
    ll Int(ll l,ll r) { return uniform_int_distribution<ll> (l,r)(mt);}
}

using namespace myrand;
const int N=1e5+32,mod=1e9+7;
const ll MxV=1e13;

struct pst
{
    struct node
    {
        int lef,rig,lazy,mn;
        ll sum;
    };

    ll val[N];
    int st=0,en=N-1,sl=0;
    node it[N*80];

    int build()
    {
        for (int i=0;i<N;i++) val[i]=Int(1,MxV);
        it[++sl]={0,0,1,0,0};
        return sl;
    }

    void combine(int id)
    {
        int lef=it[id].lef;
        int rig=it[id].rig;
        it[id].sum=it[lef].sum+it[rig].sum;
        it[id].mn=min(it[lef].mn,it[rig].mn);
    }

    void down(int id)
    {
        it[id]={++sl,++sl,0,0,0};
        it[sl-1]=it[sl]={0,0,1,0,0};
    }

    int update_range(int id,int l,int r,int u,int v)
    {
        if (l>v || r<u) return id;
        if (u<=l && r<=v)
        {
            it[++sl]={0,0,1,0,0};
            return sl;
        }
        if (it[id].lazy) return id;
        int mid=(l+r)/2;
        int new_id=++sl;
        it[new_id].lazy=0;
        it[new_id].lef=update_range(it[id].lef,l,mid,u,v);
        it[new_id].rig=update_range(it[id].rig,mid+1,r,u,v);
        combine(new_id);
        return new_id;
    }

    int update(int id,int l,int r,int v)
    {
        if (l==r)
        {
            it[++sl]={0,0,0,1,val[v]};
            return sl;
        }
        if (it[id].lazy) down(id);
        int mid=(l+r)/2;
        int new_id=++sl;
        it[new_id]=it[id];
        if (v<=mid) it[new_id].lef=update(it[id].lef,l,mid,v);
        else it[new_id].rig=update(it[id].rig,mid+1,r,v);
        combine(new_id);
        return new_id;
    }

    int lw(int id,int l,int r,int v)
    {
        if (r<v || it[id].mn) return -1;
        if (l==r) return l;
        int mid=(l+r)/2;
        int res=lw(it[id].lef,l,mid,v);
        if (res!=-1) return res;
        return lw(it[id].rig,mid+1,r,v);
    }

    int add(int root,int x)
    {
        int pos=lw(root,st,en,x);
        int res;
        if (x<pos) res=update_range(root,st,en,x,pos-1);
        else res=root;
        return update(res,st,en,pos);
    }

    bool lcp(int id1,int id2,int l,int r)
    {
        if (l==r) return it[id1].sum<it[id2].sum;
        int mid=(l+r)/2;
        int rig1=it[id1].rig;
        int rig2=it[id2].rig;
        if (it[rig1].sum!=it[rig2].sum) return lcp(rig1,rig2,mid+1,r);
        return lcp(it[id1].lef,it[id2].lef,l,mid);
    }

    bool cmp(int x,int y)
    {
        return lcp(x,y,st,en);
    }
} seg;

struct ds
{
    int u,x;
    bool operator < (const ds &obj) const
    {
        return seg.cmp(obj.x,x);
    }
};

vector<pii> G[N];
int p2w[N],n,m;

void read()
{
    cin>>n>>m;
    for (int i=1,u,v,x;i<=m;i++)
    {
        cin>>u>>v>>x;
        G[u].eb(mp(v,x));
        G[v].eb(mp(u,x));
    }
}

int dis[N],vis[N];
pii trace[N];

void process()
{
    int s,t;
    cin>>s>>t;
    p2w[0]=1;
    for (int i=1;i<N;i++) p2w[i]=(p2w[i-1]<<1)%mod;
    priority_queue<ds> q;
    for (int i=1;i<=n;i++) dis[i]=-1;
    dis[s]=seg.build();
    q.push({s,dis[s]});
    while (!q.empty())
    {
        int u=q.top().u;
        vis[u]=1;
        for (pii p : G[u])
        {
            int v=p.fi;
            int w=seg.add(dis[u],p.se);
            if (dis[v]==-1 || seg.cmp(w,dis[v]))
                dis[v]=w,trace[v]=mp(u,p.se),q.push({v,dis[v]});
        }
        while (!q.empty() && vis[q.top().u]) q.pop();
    }
    if (dis[t]==-1)
    {
        cout<<-1;
        return;
    }
    vi ans;
    ll res=0;
    while (t!=s)
    {
        res=(res+p2w[trace[t].se])%mod;
        ans.eb(t);
        t=trace[t].fi;
    }
    cout<<res<<"\n"<<ans.size()+1<<"\n"<<s<<" ";
    for (int i=(int)ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
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