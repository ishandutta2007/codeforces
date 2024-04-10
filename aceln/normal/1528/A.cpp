#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

ll dp[maxn][2];
int l[maxn],r[maxn];
vector<int> G[maxn];

void dfs(int now,int p) {
    dp[now][0]=dp[now][1]=0;
    for (int i:G[now]) {
        if (i!=p) {
            dfs(i,now);
            dp[now][0]+=max(dp[i][0]+abs(l[i]-l[now]),dp[i][1]+abs(r[i]-l[now]));
            dp[now][1]+=max(dp[i][0]+abs(l[i]-r[now]),dp[i][1]+abs(r[i]-r[now]));
        }
    }
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        for (int i=1;i<=n;i++) G[i].clear(),cin>>l[i]>>r[i];
        for (int i=1;i<=n-1;i++) {
            int u,v; cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        dfs(1,-1);
        cout<<max(dp[1][0],dp[1][1])<<'\n';
    }
}