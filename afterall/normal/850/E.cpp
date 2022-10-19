#include <bits/stdc++.h>
/// 500 485
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=21;
int dp[N][(1<<N)];
int cp[N][(1<<N)];
ll p2[N];
ll mod=1e9+7;
int32_t main(){
    sync;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0;i<s.size();i++){
        if (s[i]=='0') continue;
        ll ans=0;
        for (int j=0;j<n;j++){
            if ((i & (1<<j))) ans+=(1<<j);
        }
        dp[0][ans]++;
        dp[1][(ans ^ 1)]++;
    }
    for (int bit=1;bit<n;bit++){
        for (int i=0;i<=bit;i++){
            for (int j=0;j<(1<<n);j++){
                cp[i][j]=dp[i][j];
            }
        }
            for (int j=0;j<=bit;j++){
        for (int i=0;i<(1<<n);i++){
                dp[j+1][i]+=cp[j][(i ^ (1<<bit))];
            }
        }
    }
    p2[0]=1;
    for (int i=1;i<N;i++){
        p2[i]=p2[i-1]*2%mod;
    }
    ll ans=0;
    for (int i=0;i<(1<<n);i++){
        if (s[i]=='0') continue;
        for (int j=0;j<=n;j++){
       //     cout << i << " " << j << " " << dp[i][j] << endl;
            ans+=p2[n-j]*dp[j][i]%mod;
            ans%=mod;
        }
    }
    ans*=3;
    cout << ans%mod;
}