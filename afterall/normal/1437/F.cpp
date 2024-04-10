#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=5e3+100;
ll dp[N][N];
ll a[N];
ll mod=998244353;
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    if (a[1]<2*a[2]) kill(0);
    dp[1][1]=1;
    for (int i=2;i<=n;i++){
        for (int j=1;j<i;j++){
            if (a[j]>=a[i]*2){
                dp[i][i]+=dp[i-1][j];
            }
        }
        for (int j=1;j<i;j++){
            if (a[i]*2<=a[j]){
                dp[i][j]=dp[i-1][j]*(i-1)%mod;
            }
            else {
                dp[i][j]=dp[i-1][j]*(i-2)%mod;
            }
        }
        //for (int j=1;j<=i;j++){
        //    cout << i << " " << j << " " << dp[i][j] << endl;
        //}
    }
    ll ans=0;
    for (int i=1;i<=n;i++) ans+=dp[n][i];
    cout << ans%mod << endl;
}