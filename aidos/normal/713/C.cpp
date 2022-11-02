#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)400200;
const ll inf = (1ll<<50);
int n, m;
int a[maxn];
int b[maxn];
ll dp[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
        b[i] = a[i];
    }
    sort(b, b + n);
    int k = unique(b,b+n) - b;
    for(int i = 0; i < k; i++) {
        dp[i] = abs(a[0] - b[i]);
    }
    for(int i = 1; i < n; i++) {
        ll cur = 1ll<<50;
        for(int j = 0; j < k; j++) {
            cur = min(cur, dp[j]);
            dp[j] = cur + abs(a[i] - b[j]);
        }
    }
    cout << *min_element(dp, dp + k) << "\n";

}
int main() {

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}