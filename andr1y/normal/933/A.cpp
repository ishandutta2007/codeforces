#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 2000
#define INF 101111111111111
using namespace std;
ll a[N], dp[N][4];
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i =0;i<n;i++) cin >> a[i];
    for(ll i =0;i<n;i++){
        if(i > 0){
            dp[i][0] = (a[i] == 1 ? 1 : 0) + dp[i-1][0];
            dp[i][1] = (a[i] == 2 ? 1 : 0) + max(dp[i-1][0], dp[i-1][1]);
            dp[i][2] = (a[i] == 1 ? 1 : 0) + max(dp[i-1][1], dp[i-1][2]);
            dp[i][3] = (a[i] == 2 ? 1 : 0) + max(dp[i-1][2], dp[i-1][3]);
        }else{
            dp[i][0] = (a[i] == 1 ? 1 : 0);
            dp[i][1] = (a[i] == 2 ? 1 : 0);
            dp[i][2] = (a[i] == 1 ? 1 : 0);
            dp[i][3] = (a[i] == 2 ? 1 : 0);
        }
    }
    cout << max(dp[n-1][3], max(dp[n-1][1], max(dp[n-1][0], dp[n-1][2])));
}