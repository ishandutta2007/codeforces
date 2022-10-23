#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define arr vector<int>
#define mp make_pair
#define all(vt) vt.begin(),vt.end()
const ll maxn=2e5+1,mod=1e9+7,inf=1e18,siz=500;

struct ds
{
    int t,x,y,z;
};

vector<pii> G[maxn];
ds a[maxn];
int n,m,deg[maxn],root[maxn];
arr group[maxn],near_group[maxn],Gn[maxn];

void inquery(int i)
{
    int x,y,c;
    cin>>x>>y>>c;
    a[i]={1,x,y,c};
    deg[x]++;
    deg[y]++;
    G[x].pb(mp(c,0));
    G[y].pb(mp(c,0));
}

void read()
{
    int c,q,x,y;
    cin>>n>>m>>c>>q;
    for (int i=1;i<=m;i++) inquery(i);
    char ch;
    for (int i=1;i<=q;i++)
    {
        cin>>ch;
        if (ch=='+') inquery(i+m);
        else cin>>x>>y,a[i+m]={2,x,y,0};
    }
    m+=q;
}

void build()
{
    for (int i=1;i<=n;i++)
    {
        sort(all(G[i]));
        G[i].pb(mp(0,0));
        vector<pii> tmp;
        for (int j=0;j<G[i].size()-1;j++)
            if (G[i][j].fi!=G[i][j+1].fi) tmp.pb(mp(G[i][j].fi,0));
        G[i]=tmp;
    }
    for (int i=1;i<=n;i++) root[i]=i,group[i].pb(i);
}

void merg(int x,int y)
{
    if (x==y) return;
    if (group[x].size()<group[y].size()) swap(x,y);
    for (int i=0;i<group[y].size();i++) root[group[y][i]]=x,group[x].pb(group[y][i]);
    group[y].clear();
    vector<int> tmp(near_group[x].size()+near_group[y].size());
    merge(all(near_group[x]),all(near_group[y]),tmp.begin());
    tmp.pb(0);
    near_group[x].clear();
    for (int i=0;i<tmp.size()-1;i++)
        if (tmp[i]!=tmp[i+1]) near_group[x].pb(tmp[i]);
    near_group[y].clear();
}

void addto(int x,int y)
{
    int tmp=lower_bound(all(near_group[x]),y)-near_group[x].begin();
    if (tmp==near_group[x].size() || near_group[x][tmp]!=y)
    {
        arr tt;
        for (int i=0;i<tmp;i++) tt.pb(near_group[x][i]);
        tt.pb(y);
        for (int i=tmp;i<near_group[x].size();i++) tt.pb(near_group[x][i]);
        near_group[x]=tt;
    }
}

void update(int x,int y,int z)
{
    int tmp=(lower_bound(all(G[x]),mp(z,0))-G[x].begin());
    if (G[x][tmp].se) merg(root[G[x][tmp].se],root[y]);
    else G[x][tmp].se=y;
    if (deg[y]>=siz) addto(root[x],y);
    Gn[x].pb(y);
}

bool query(int x,int y)
{
    if (root[x]==root[y]) return true;
    if (deg[y]>=siz)
    {
        int r=root[x];
        int tmp=lower_bound(all(near_group[r]),y)-near_group[r].begin();
        return (tmp<near_group[r].size()) && (near_group[r][tmp]==y);
    }
    else
    {
        for (int i=0;i<Gn[y].size();i++)
            if (root[Gn[y][i]]==root[x]) return true;
        return false;
    }
}

void process()
{
    for (int i=1;i<=m;i++)
        if (a[i].t==1)
        {
            update(a[i].x,a[i].y,a[i].z);
            update(a[i].y,a[i].x,a[i].z);
        }
        else
        {
            if (query(a[i].x,a[i].y)) printf("Yes\n");
            else printf("No\n");
        }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    build();
    process();
    return 0;
}