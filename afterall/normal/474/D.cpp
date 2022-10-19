#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+10;
int dp[N];
int mod=1000000007;
int ps[N];
int32_t main(){

    dp[0]=1;
    int t,k;
    cin >> t >> k;

    for (int i=1;i<N;i++){
        dp[i]=dp[i-1];
        if (i>=k) dp[i]+=dp[i-k];
        dp[i]%=mod;
    }
    for (int i=0;i<N;i++){
        ps[i]=ps[i-1]+dp[i];
        ps[i]%=mod;
    }
    while(t--){
        ll x,y;
        cin >> x >> y;
        int ans=ps[y]-ps[x-1];
        ans+=mod;
        ans%=mod;
        cout << ans << endl;
    }
}