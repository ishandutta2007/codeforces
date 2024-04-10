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
int ans=-maxll;
int a[arr];
vi cur;
int dp[arr];
int cnt[arr];

void dfs(int now=1,int pred=-1)
{
    cnt[now]=a[now];
    for (auto wh:reb[now])
        if (wh!=pred)
        {
            dfs(wh,now);
            cnt[now]+=cnt[wh];
        }
    dp[now]=cnt[now];
    for (auto wh:reb[now])
        if (wh!=pred)
            dp[now]=max(dp[now],dp[wh]);
    cur.clear();
    for (auto wh:reb[now])
        if (wh!=pred)
            cur.pb(dp[wh]);
    if (cur.size()<2) return;
    sort(all(cur),greater<int>());
    ans=max(ans,cur[0]+cur[1]);
}

main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs();
    if (ans==-maxll) return cout<<"Impossible", 0;
    cout<<ans;
}