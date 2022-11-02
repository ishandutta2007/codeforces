#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 309;
int a[maxn];
int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int e = 0; e < i; e++) {
            if (a[e] < a[i]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}