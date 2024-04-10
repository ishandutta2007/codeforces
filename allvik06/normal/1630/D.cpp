#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <map>

using namespace std;
#define int long long
const int INF = 1e17;

inline int gcd(int a, int b) {
    for (; b > 0; a %= b, swap(a, b)) {}
    return a;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m, all_sum = 0;
        cin >> n >> m;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            all_sum += a[i];
        }
        int g = 0;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            g = gcd(g, x);
        }
        vector <int> cnt(g), sum(g), minn(g, INF), maxx(g, -INF);
        for (int i = 0; i < n; ++i) {
            int gr = i % g;
            if (a[i] < 0) {
                ++cnt[gr];
                sum[gr] += a[i];
                maxx[gr] = max(maxx[gr], a[i]);
            } else {
                minn[gr] = min(minn[gr], a[i]);
            }
        }
        int res = -INF;
        for (int p = 0; p <= 1; ++p) {
            int now = 0;
            for (int i = 0; i < g; ++i) {
                if (p == cnt[i] % 2) {
                    now += -2 * sum[i];
                } else {
                    int val = -INF;
                    if (maxx[i] != -INF) val = -2 * (sum[i] - maxx[i]);
                    if (minn[i] != INF) val = max(val, -2 * (sum[i] + minn[i]));
                    now += val;
                }
            }
            res = max(res, now + all_sum);
        }
        cout << res << "\n";
    }
}

/*

 */