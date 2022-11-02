#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)100200;
const ll inf = (1ll<<50);
ll n, k;
ll a[maxn], b[maxn];
ll dp[555][555];
void solve() {
    cin >> n >> k;
    ll sa = 0;
    ll sb = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sa += a[i];
        sb += b[i];
    }

    ll s = sa + sb;
    if(sa/k + sb/k == s/k) {
        cout << s/k << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] >= k && b[i] >= k) {
            cout << s/k << "\n";
            return;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            if(dp[i-1][j] >= 1) {
                for(int x = 0; x < k && x <= a[i]; x++) {
                    if((a[i]+b[i] - x) % k <= b[i]) dp[i][(x+j)% k] = 1;
                }
            }
        }
    }
    for(int i = 0; i < k; i++) {
        if(dp[n][i] && (s - i)/k == s/k) {
            cout << s/k << "\n";
            return;
        }
    }
    cout << s/k-1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}