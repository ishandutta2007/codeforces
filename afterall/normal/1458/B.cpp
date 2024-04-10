#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=110;
ll dp[2][N][N*N];
ll a[N];
ll b[N];
int Main(){
    ll n;
    cin >> n;
    ll t=0;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
        t+=b[i];
    }
    memset(dp,-63,sizeof dp);
    dp[0][0][0]=0;
    for (int i=1;i<=n;i++){
        dp[i%2][0][0]=0;
        for (int j=1;j<=i;j++){
            for (int s=1;s<N*N;s++){
                dp[i%2][j][s]=dp[(i-1)%2][j][s];
                if (s>=a[i]){
                    dp[i%2][j][s]=max(dp[i%2][j][s],dp[(i-1)%2][j-1][s-a[i]]+b[i]);
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        ld ma=0;
        for (int s=0;s<N*N;s++){
            ma=max(ma,min((ld)s,(ld)dp[n%2][i][s]+((ld)t-(ld)dp[n%2][i][s])/(ld)2));
        }
        cout << fixed << setprecision(10) << ma << endl;
    }

}
int32_t main(){
    sync;
    ll t;
    t=1;
   // cin >> t;
    while(t--){
        Main();
    }
}