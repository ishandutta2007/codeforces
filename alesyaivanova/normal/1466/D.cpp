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

const int maxn = 2e5 + 9;
pii w[maxn];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i].ff;
        w[i].ss = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        w[a].ss++;
        w[b].ss++;
    }
    sort(w, w + n);
    reverse(w, w + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += w[i].ff;
        w[i].ss--;
    }
    cout << ans << " ";
    for (int i = 0; i < n; i++) {
        while (w[i].ss) {
            ans += w[i].ff;
            cout << ans << " ";
            w[i].ss--;
        }
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}