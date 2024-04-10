#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e3 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
ll dp[maxn];
ll lim = 1e18;
void upd(ll &v, ll u) {
    if(v == -1 || v > u) v = u;
}
void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    dp[1] = 1;
    for(int i=2; i <= 100; i++) {
        int ok = 1;
        for(int j = 2; j < i; j++) if(i % j == 0) ok = 0;
        if(!ok) continue;
        for(int j = n; j >= 1; j--) {
            if(dp[j] == -1) continue;
            ll val = dp[j];
            int cnt = 0;
            while(lim/val >= i && val * i <= lim && (j * (cnt+2)) <= n) {
                cnt++;
                val *= i;
                upd(dp[j * (cnt+1)], val);
            }
        }
    }
    cout << dp[n] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}