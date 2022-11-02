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

const int maxn = 3e5 + 9;
int c[maxn];
int k[maxn];
int n, m;
int inf = 1e9;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        k[i]--;
    }
    for (int i = 0; i < m; i++)
        cin >> c[i];
    int pt = 0;
    sort(k, k + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += c[k[i]];
    int mi = inf;
    int opt = ans;
    for (int i = 0; i < n; i++) {
        mi = min(mi, k[n - i - 1] - (n - i - 1));
        if (mi + (n - i - 1) >= 0) {
            ans += c[i];
            ans -= c[k[n - i - 1]];
            opt = min(opt, ans);
        } else {
            break;
        }
    }
    cout << opt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}