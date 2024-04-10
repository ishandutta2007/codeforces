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
#define N 200005
#define INF 101111111111111
using namespace std;
ll dp[N][2], a[N], b[N];
int main(){
    ll n, c;
    cin >> n >> c;
    for(ll i  =0;i<n-1;i++) cin >> a[i];
    for(ll i  =0;i<n-1;i++) cin >> b[i];
    dp[0][0] = 0, dp[0][1] = c;
    for(ll i = 1;i<n;i++){
        dp[i][0] = min(dp[i-1][0], dp[i-1][1])+a[i-1];
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]-c)+c+b[i-1];
    }
    for(ll i =0;i<n;i++){
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
}