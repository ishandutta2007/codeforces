#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
//#define _USE_MATH_DEFINE
using namespace std;

const int maxn = 1005;

int min_bal[maxn][maxn];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = pr[i];
        if (i % 2 == 0) {
            pr[i + 1] += a[i];
        } else {
            pr[i + 1] -= a[i];
        }
    }
    for (int i = 1; i < n; i += 2) {
        for (int j = i + 1; j < n; j += 2) {
            if (j == i + 1) {
                min_bal[i][j] = -a[i];
            } else {
                min_bal[i][j] = min(min_bal[i][j - 2], pr[j] - pr[i]);
            }
        }
    }
    unsigned int ans = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = i + 1; j < n; j += 2) {
            if (j == i + 1) {
                ans += min(a[i], a[j]);
            } else {
                if (min_bal[i + 1][j - 1] + a[i] >= 0) {
                    int val1 = a[i] + min_bal[i + 1][j - 1];
                    int val2 = a[j] - (pr[j] - pr[i + 1] - min_bal[i + 1][j - 1]);
                    if (val2 >= 0) {
                        ans += min(val1, val2) + 1;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}