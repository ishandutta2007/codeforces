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
#define int long long

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
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

vi reb[arr];
bool use[arr];

void dfs(int now,vi& cur)
{
    cur.pb(now);
    use[now]=true;
    for (auto wh:reb[now])
        if (!use[wh])
            dfs(wh,cur);
}

vi comp[arr];
int dp[ar][ar];

main()
{
    fast;
    int n,m,maxw;
    cin>>n>>m>>maxw;
    vi w;
    w.resize(n);
    for (auto &i:w)
        cin>>i;
    vi b;
    b.resize(n);
    for (auto &i:b)
        cin>>i;
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        //cout<<" REB :: "<<u<<" "<<v<<"\n";
        reb[u].pb(v);
        reb[v].pb(u);
    }
    int cnt_comp=0;
    for (int i=1;i<=n;i++)
        if (!use[i])
        {
            dfs(i,comp[cnt_comp]);
            cnt_comp++;
        }
    //for (int i=0;i<3;i++)
      //  for (auto j:comp[i])
        //    cout<<i<<" :: "<<j<<" | !\n";
    for (int i=1;i<=cnt_comp;i++)
    {
        int num_comp=i-1;
        int sum_b=0;
        for (auto k:comp[num_comp])
            sum_b+=b[k-1];
        int sum_w=0;
        for (auto k:comp[num_comp])
            sum_w+=w[k-1];
        //cout<<"all :: "<<i<<" "<<sum_w<<" "<<sum_b<<"\n";
        for (int j=sum_w;j<=maxw;j++)
            dp[i][j]=max(dp[i][j],dp[i-1][j-sum_w]+sum_b);
        for (auto k:comp[num_comp])
            for (int j=w[k-1];j<=maxw;j++)
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[k-1]]+b[k-1]);
        for (int j=0;j<=maxw;j++)
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
    }
    //for (int i=1;i<=2;i++)
      //  for (int j=0;j<=maxw;j++)
        //    cout<<i<<" "<<j<<" "<<" :: DP :: "<<dp[i][j]<<"\n";
    int ans=0;
    for (int i=0;i<ar;i++)
        for (int j=0;j<ar;j++)
            ans=max(ans,dp[i][j]);
    cout<<ans;
}