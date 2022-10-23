#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;

struct edge {ll u,v,w;};
vector<int> G[N],G2[N];
edge rev[N*25];
int mark[N*25],m,n;

void read()
{
    cin>>n>>m;
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        G[u].pb(i);
        G2[v].pb(i);
        rev[i]={u,v,w};
    }
}

void add(int u,int v,int w)
{
    m++;
    rev[m]={u,v,w};
    G[u].pb(m);
    G2[v].pb(m);
}

bool cmp(edge t1,edge t2)
{
    if (t1.u==t2.u) return t1.v<t2.v;
    return t1.u<t2.u;
}

vector<edge> compress(vector<edge> &vt)
{
    vector<edge> res;
    ll sl=0;
    for (int i=0;i<(int)vt.size()-1;i++)
        if (vt[i].u==vt[i+1].u && vt[i].v==vt[i+1].v) sl+=vt[i].w;
        else
        {
            sl+=vt[i].w;
            if (sl) res.pb({vt[i].u,vt[i].v,sl});
            sl=0;
        }
    if (vt.size()) sl+=vt.back().w;
    if (sl && vt.size()) res.pb({vt.back().u,vt.back().v,sl});
    return res;
}

void process()
{
    for (int t=1;t<=m;t++)
    if (!mark[t])
    {
        ll u=rev[t].u,v=rev[t].v,w=rev[t].w;
        if (u==v)
        {
            mark[t]=1;
            continue;
        }
        while (!G[v].empty() && mark[G[v].back()]) G[v].pop_back();
        mark[t]=1;
        if (!G[v].empty())
        {
            int t2=G[v].back();
            mark[t2]=1;
            add(u,rev[t2].v,min(w,rev[t2].w));
            if (w>rev[t2].w) add(u,v,w-rev[t2].w);
            else if (w<rev[t2].w) add(rev[t2].u,rev[t2].v,rev[t2].w-w);
            continue;
        }
        while (!G2[u].empty() && mark[G2[u].back()]) G2[u].pop_back();
        if (!G2[u].empty())
        {
            int t2=G2[u].back();
            mark[t2]=1;
            add(rev[t2].u,v,min(rev[t2].w,w));
            if (w>rev[t2].w) add(u,v,w-rev[t2].w);
            else if (w<rev[t2].w) add(rev[t2].u,rev[t2].v,rev[t2].w-w);
            continue;
        }
        mark[t]=0;
    }
    vector<edge> ans;
    for (int i=1;i<=m;i++)
        if (!mark[i]) ans.pb(rev[i]);
    sort(all(ans),cmp);
    ans=compress(ans);
    cout<<ans.size()<<"\n";
    for (edge x : ans) cout<<x.u<<" "<<x.v<<" "<<x.w<<"\n";
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