#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
bool check=1;
vector <pair<int,int> > vec[200000];
vector <int> can[200000];
int type[200000],r[200000];
void dfs(int u ,int now)
{
    //cout<<u<<' '<<now<<'\n';
    if (type[u]!=-1)
    {
        if (type[u]!=now) check=0;
        return;
    }
    type[u]=now;
    for (int i=0;i<vec[u].size();i++)
        dfs(vec[u][i].fir,(now+vec[u][i].sec)%2);
}
signed main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>r[i];
        r[i]=!r[i];
    }

    for (int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        while (x--)
        {
            int a;
            cin>>a;
            can[a].pb(i);
        }
    }
    for (int i=1;i<=n;i++)
    {
        vec[can[i][0]].pb({can[i][1],r[i]});
        vec[can[i][1]].pb({can[i][0],r[i]});
    }
    for (int i=1;i<=m;i++)
        type[i]=-1;
    for (int i=1;i<=m;i++)
    {
        if (type[i]==-1)
        {
            dfs(i,0);
        }
    }
    if (check) cout<<"YES"; else cout<<"NO";
}