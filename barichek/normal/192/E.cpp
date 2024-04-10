#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

int n,m,lg,dist[arr],glub[arr],pred[50][arr],ans[arr],sum[arr];
vi all_ans,reb[arr];
vector<pii> edge;

void dfs_sum(int now,int pr=0)
{
    int res=0;
    for (auto where:reb[now])
        if (where!=pr)
        {
            dfs_sum(where,now);
            res+=sum[where];
        }
    sum[now]=res+ans[now];
}

void dfs(int now,int pr=1,int len=0)
{
    glub[now]=++len;
    pred[0][now]=pr;
    for (auto where:reb[now])
        if (where!=pr) dfs(where,now,len);
}

void init_lca()
{
    lg=log2(n);
    for (int k=1;1<<k<=n;k++)
        for (int i=1;i<=n;i++)
            pred[k][i]=pred[k-1][pred[k-1][i]];
}

int lca(int u,int v)
{
    if (glub[u]>glub[v]) swap(u,v);
    for (int i=lg;i>=0;i--)
        if (glub[v]-glub[u]>=1<<i)
            v=pred[i][v];
    if (u==v) return u;
    for (int i=lg;i>=0;i--)
        if (pred[i][u]!=pred[i][v])
            u=pred[i][u],
            v=pred[i][v];
    return pred[0][u];
}

int main()
{
    fast;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int zn1,zn2;
        cin>>zn1>>zn2;
        reb[zn1].pb(zn2);
        reb[zn2].pb(zn1);
        edge.pb(mp(zn1,zn2));
    }
    dfs(1);
    init_lca();
    cin>>m;
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        ans[u]++;
        ans[v]++;
        ans[lca(u,v)]-=2;
    }
    dfs_sum(1);
    for (auto i:edge)
    {
        if (pred[0][i.fir]==i.sec) swap(i.fir,i.sec);
        all_ans.pb(sum[i.sec]);
    }
    for (auto i:all_ans)
        cout<<i<<" ";
}