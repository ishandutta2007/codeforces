#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        bool ok = 1;
        vector<int> bad(n);
        vector<ll> sum(2);
        sum[0] += a[0];
        multiset<ll> mind, maxd;
        vector<ll> val(n);
        vector<ll> totalsum;
        vector<int> is_min(n);
        for (int i = 1; i < n; i++) {
            if (a[i] < sum[1 - i % 2] - sum[i % 2]) {
                bad[i] = 1;
                ok = 0;
                if (i % 2 == 0) {
                    val[i] = -a[i] + (sum[1] - sum[0]);
                    is_min[i] = 1;
                    mind.insert(val[i]);
                }
                else {
                    val[i] = a[i] - (sum[0] - sum[1]);
                    maxd.insert(val[i]);
                }
            } else {
                if (i % 2 == 0) {
                    val[i] = -a[i] + (sum[1] - sum[0]);
                    is_min[i] = 1;
                    mind.insert(val[i]);
                }
                else {
                    val[i] = a[i] - (sum[0] - sum[1]);
                    maxd.insert(val[i]);
                }
            }
            if (i < n - 1) sum[i % 2] += a[i];
        }
        totalsum = sum;
        if (ok && a[n - 1] == sum[1 - (n - 1) % 2] - sum[(n - 1) % 2]) {
            cout << "YES\n";
            continue;
        }
        sum[0] = sum[1] = 0;
        bool YES = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (is_min[i + 1]) mind.erase(mind.find(val[i + 1]));
            else maxd.erase(maxd.find(val[i + 1]));
            bool ok = 1;
            if (i % 2 == 0) {
                if (sum[0] + a[i + 1] - sum[1] > a[i]) ok = 0;
                if (sum[1] - sum[0] > a[i + 1]) ok = 0;
            } else {
                if (sum[1] + a[i + 1] - sum[0] > a[i]) ok = 0;
                if (sum[0] - sum[1] > a[i + 1]) ok = 0;
            }
            if (i + 1 < n - 1) {
                totalsum[i % 2] -= a[i];
                totalsum[1 - i % 2] += a[i];
                totalsum[(i + 1) % 2] -= a[i + 1];
                totalsum[1 - (i + 1) % 2] += a[i + 1];
                if ((n - 1) % 2 == 0) {
                    if (totalsum[1] - totalsum[0] != a[n - 1]) ok = 0;
                } else {
                    if (totalsum[0] - totalsum[1] != a[n - 1]) ok = 0;
                }
                totalsum[i % 2] += a[i];
                totalsum[1 - i % 2] -= a[i];
                totalsum[(i + 1) % 2] += a[i + 1];
                totalsum[1 - (i + 1) % 2] -= a[i + 1];
                ll cur_d = 0;
                if (i % 2 == 0) cur_d = 2 * (a[i + 1] - a[i]);
                else cur_d = 2 * (a[i] - a[i + 1]);
                ll mn = -INFLL, mx = INFLL;
                if (mind.size()) mn = *mind.rbegin();
                if (maxd.size()) mx = *maxd.begin();
                if (ok && cur_d >= mn && cur_d <= mx) {
                    cout << "YES\n";
                    YES = 1;
                    break;
                }
            } else {
                totalsum[i % 2] -= a[i];
                totalsum[1 - (i + 1) % 2] += a[i + 1];
                if ((n - 1) % 2 == 0) {
                    if (totalsum[1] - totalsum[0] != a[n - 2]) ok = 0;
                } else {
                    if (totalsum[0] - totalsum[1] != a[n - 2]) ok = 0;
                }
                if (ok) {
                    cout << "YES\n";
                    YES = 1;
                    break;
                }
            }
            sum[i % 2] += a[i];
            if (bad[i]) break;
        }
        if (!YES) cout << "NO\n";
    }
    return 0;
}
/*
1
5
2100 1900 1600 3000 1600
*/