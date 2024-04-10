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

ll dp[5007][5007];
ll a[5007],b[5007];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];

    ll ans=0;
    for (int i=1;i<=n;i++) ans+=a[i]*b[i];

    for (int i=1;i<=n-1;i++) dp[i][i+1] = a[i]*b[i+1]+a[i+1]*b[i]-a[i]*b[i]-a[i+1]*b[i+1];

    for (int len=3;len<=n;len++) {
        for (int i=1;i+len-1<=n;i++) {
            dp[i][i+len-1] = dp[i+1][i+len-2] + a[i] * b[i+len-1] + a[i+len-1] * b[i]
            -a[i]*b[i]-a[i+len-1]*b[i+len-1];
        }
    }

    ll delta = 0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) delta=max(delta,dp[i][j]);
    cout<<ans+delta<<'\n';
}