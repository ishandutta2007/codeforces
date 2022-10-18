#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

vector<pii> reb[arr];
int dp[arr],rdp[arr];

int dfs(int now=1,int pred=1)
{
    int res=0;
    for (auto wh:reb[now])
        if (wh.fir!=pred)
            res+=dfs(wh.fir,now)+wh.sec;
    dp[now]=res;
    return res;
}

void rdfs(int now=1,int pred=1)
{
    int sum_dp=0;
    for (auto wh:reb[now])
        if (wh.fir!=pred)
            sum_dp+=dp[wh.fir]+wh.sec;
    for (auto wh:reb[now])
        if (wh.fir!=pred)
            rdp[wh.fir]=sum_dp-dp[wh.fir]+(wh.sec==0)-(wh.sec==1)+rdp[now];
    for (auto wh:reb[now])
        if (wh.fir!=pred)
            rdfs(wh.fir,now);
}

main()
{
    fast;
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        reb[u].pb(mp(v,0));
        reb[v].pb(mp(u,1));
    }
    dfs();
    rdfs();
    int ans=maxint;
    vi res;
    for (int i=1;i<=n;i++)
        ans=min(ans,dp[i]+rdp[i]);
    for (int i=1;i<=n;i++)
        if (dp[i]+rdp[i]==ans)
            res.pb(i);
    cout<<ans<<"\n";
    for (auto i:res)
        cout<<i<<" ";
}