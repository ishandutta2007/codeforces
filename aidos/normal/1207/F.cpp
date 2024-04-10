#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)5e5 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
int n, m;
ll a[maxn];
const int K = 720;
ll sum[K + 1][K + 1];
void solve() {
    cin >> m;
    for(int i = 0; i < m; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            a[x] += y;
            for(int j = 1; j < K; j++) {
                sum[j][x % j]+=y;
            }
        } else {
            if(x < K) {
                cout << sum[x][y] << "\n";
            } else {
                ll ans = 0;
                for(int j = y; j <= 500000; j += x) {
                    ans += a[j];
                }
                cout << ans << "\n";
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}