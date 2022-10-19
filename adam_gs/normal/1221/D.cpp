#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
void solve() {
    int n;
    cin >> n;
    ll dp[2][3], lst=-10;
    rep(i, 3) {
        dp[0][i]=0;
        dp[1][i]=INF;
    }
    while(n--) {
        ll a, b;
        cin >> a >> b;
        rep(i, 3) rep(j, 3) if(lst+j!=a+i) dp[1][i]=min(dp[1][i], dp[0][j]+i*b);
        rep(i, 3) {
            dp[0][i]=dp[1][i];
            dp[1][i]=INF;
        }
        lst=a;
    }
    cout << min(dp[0][0], min(dp[0][1], dp[0][2])) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int _=1;
    cin >> _;
    while(_--) solve();
}