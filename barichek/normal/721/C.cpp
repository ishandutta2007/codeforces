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
const ld eps=1e-10;

///---program start---///

int n,m,k;
vector<pii> reb[arr];
vi topolog;
int dp[5001][5001];
int from[5001][5001];
bool use[arr];

void dfs(int now=1,int pred=1)
{
    use[now]=true;
    for (auto wh:reb[now])
        if (!use[wh.fir])
            dfs(wh.fir,now);
    topolog.pb(now);
}

main()
{
    fast;
    cin>>n>>m>>k;
    while (m--)
    {
        int u,v,t;
        cin>>u>>v>>t;
        reb[u].pb(mp(v,t));
    }
    dfs();
    reverse(all(topolog));
    for (int i=0;i<5001;i++)
        for (int j=0;j<5001;j++)
            dp[i][j]=1e9+10;
    dp[1][1]=0;
    for (auto i:topolog)
        for (int j=0;j<n;j++)
            for (auto wh:reb[i])
            {
                if (dp[i][j]>k) continue;
                if (dp[wh.fir][j+1]>dp[i][j]+wh.sec)
                    dp[wh.fir][j+1]=dp[i][j]+wh.sec,
                    from[wh.fir][j+1]=i;
            }
    int ans=0;
    for (int i=0;i<=n;i++)
        if (dp[n][i]<=k) ans=i;
    cout<<ans<<"\n";
    vi res;
    int now=n;
    while (now!=0)
    {
        res.pb(now);
        now=from[now][ans--];
    }
    reverse(all(res));
    for (auto i:res)
        cout<<i<<" ";
}