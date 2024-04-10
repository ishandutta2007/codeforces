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
const int N=510;
ll dp[2][N][N];
ll d[N];
ll A[N];
int32_t main(){
    sync;
    ll n,k,l;
    cin >> n >> l >> k;
    vector <pii> a;
    for (int i=0;i<n;i++){
        cin >> d[i];
    }
    for (int i=0;i<n;i++) cin >> A[i];
    d[n]=l;
    memset(dp,31,sizeof dp);
    dp[0][0][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=n;j++) for (int last=0;last<=n;last++) dp[i%2][j][last]=(ll)1e12;
        for (int j=0;j<=n;j++){
            for (int last=0;last<i;last++){
                dp[(i%2)][j][last]=min(dp[(i%2)][j][last],dp[((i-1)%2)][j][last]+A[last]*(d[i]-d[i-1]));
                dp[(i%2)][j+1][i]=min(dp[(i%2)][j+1][i],dp[((i-1)%2)][j][last]+A[last]*(d[i]-d[i-1]));
            }
        }
       // cout << dp[(i%2)][0][0] << endl;
    }
    ll ans=(ll)1e12;
    for (int i=0;i<=k;i++){

        ans=min(ans,dp[n%2][n-i][n]);
    }
    cout << ans << endl;

}