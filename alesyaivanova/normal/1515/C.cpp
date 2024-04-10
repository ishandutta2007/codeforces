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

const int maxn = 1e5 + 9;
//int h[maxn];
int n, m, x;

void solve() {
    cin >> n >> m >> x;
    set<pii> s;
    for (int i = 0; i < m; i++) {
        s.emplace(0, i);
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        pii cur = *s.begin();
        cout << cur.ss + 1 << " ";
        s.erase(s.begin());
        s.emplace(cur.ff + h, cur.ss);
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}