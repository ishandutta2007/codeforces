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
#define arr vector<pii>
const ll maxn=2e5+10,mod=1e9+7,inf=1e18,siz=500;

struct ds { int t,x,y; };

arr edge,cur_edge;
vector<int> G[maxn],CG[maxn];
int n,m,on[maxn],root[maxn],tplt,mark[maxn],visit[maxn],last=0;
vector<ds> query;

arr compress(arr vt)
{
    arr res;
    for (int i=0;i<(int)vt.size()-1;i++)
        if (vt[i]!=vt[i+1]) res.pb(vt[i]);
    if (!vt.empty()) res.pb(vt.back());
    return res;
}

void dfs(int u,int r)
{
    root[u]=r;
    for (int i=0;i<(int)G[u].size();i++)
        if (!root[G[u][i]]) dfs(G[u][i],r);
}

void rebuild()
{
    for (int i=1;i<=n;i++) G[i].clear(),root[i]=0;
    for (int i=0;i<(int)edge.size();i++)
    {
        G[edge[i].fi].pb(edge[i].se);
        G[edge[i].se].pb(edge[i].fi);
    }
    tplt=0;
    for (int i=1;i<=n;i++)
        if (!root[i]) tplt++,dfs(i,tplt);
}

void connect(int u,int v)
{
    if (u>v) swap(u,v);
    pii tmp=mp(u,v);
    int vt=lower_bound(all(cur_edge),tmp)-cur_edge.begin();
    on[vt]^=1;
}

vector<int> all_visit;

void dfs2(int u)
{
    visit[u]=1;
    all_visit.pb(u);
    for (int i=0;i<(int)CG[u].size();i++)
        if (!visit[CG[u][i]]) dfs2(CG[u][i]);
}

bool check(int u,int v)
{
    if (root[u]==root[v]) return true;
    vector<int> active;
    for (int i=0;i<(int)cur_edge.size();i++)
        if (on[i] && root[cur_edge[i].fi]!=root[cur_edge[i].se])
        {
            int ru=root[cur_edge[i].fi],rv=root[cur_edge[i].se];
            if (!mark[ru]) mark[ru]=1,active.pb(ru);
            if (!mark[rv]) mark[rv]=1,active.pb(rv);
            CG[ru].pb(rv);
            CG[rv].pb(ru);
        }
    int ru=root[u],rv=root[v];
    bool check=true;
    dfs2(ru);
    if (!visit[rv]) check=false;
    for (int i=0;i<(int)active.size();i++)
    {
        mark[active[i]]=0;
        CG[active[i]].clear();
    }
    for (int i=0;i<(int)all_visit.size();i++) visit[all_visit[i]]=0;
    all_visit.clear();
    return check;
}

void solve()
{
    arr tmp;
    for (int i=0;i<(int)cur_edge.size();i++)
        if (on[i]) tmp.pb(cur_edge[i]);
    cur_edge=tmp;
    tmp.clear();
    tmp.resize(edge.size()+cur_edge.size());
    merge(all(edge),all(cur_edge),tmp.begin());
    edge=compress(tmp);
    cur_edge.clear();
    for (int i=0;i<(int)query.size();i++)
    if (query[i].t==1)
    {
        cur_edge.pb(mp(query[i].x,query[i].y));
        cur_edge.pb(mp(query[i].x%n+1,query[i].y%n+1));
    }
    for (int i=0;i<(int)cur_edge.size();i++)
        if (cur_edge[i].fi>cur_edge[i].se) swap(cur_edge[i].fi,cur_edge[i].se);
    sort(all(cur_edge));
    cur_edge=compress(cur_edge);
    for (int i=0;i<(int)cur_edge.size();i++) on[i]=0;
    tmp.clear();
    int j=0;
    for (int i=0;i<(int)edge.size();i++)
    {
        while (j<(int)cur_edge.size() && cur_edge[j]<edge[i]) j++;
        if (j<(int)cur_edge.size() && cur_edge[j]==edge[i]) on[j]=1;
        else tmp.pb(edge[i]);
    }
    edge=tmp;
    rebuild();
    for (int i=0;i<(int)query.size();i++)
        if (query[i].t==1) connect((query[i].x+last-1)%n+1,(query[i].y+last-1)%n+1);
        else
        {
            if (check((query[i].x+last-1)%n+1,(query[i].y+last-1)%n+1)) last=1;
            else last=0;
            cout<<last;
        }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    while (m)
    {
        if (m>=siz)
        {
            m-=siz;
            for (int i=1,t,x,y;i<=siz;i++) cin>>t>>x>>y,query.pb({t,x,y});
        }
        else
        {
            for (int i=1,t,x,y;i<=m;i++) cin>>t>>x>>y,query.pb({t,x,y});
            m=0;
        }
        solve();
        query.clear();
    }
    return 0;
}