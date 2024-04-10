#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<pair<pii, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i].se = i;
        cin >> a[i].fi.fi >> a[i].fi.se;
    }
    sort(all(a));
    vector<pair<pii, int>> b;
    b.pb(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i].fi.se >= b.back().fi.se) b.pb(a[i]);
    }
    vector<int> g(k);
    for (auto &c : g) cin >> c;
    g.pb(0);
    g.pb(s);
    sort(all(g));
    k += 2;
    n = b.size();
    int left = -1, right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int cur = 0;
        bool ok = 1;
        int v = b[mid].fi.se;
        //cout << '!' << " " << v << endl;
        for (int i = 0; i + 1 < k; i++) {
            int len = g[i + 1] - g[i];
            if (len > v) {
                ok = 0;
                break;
            }
            int fast = v - len;
            fast = min(fast, len);
            cur += fast + 2 * (len - fast);
        }
        //cout << ok << " " << cur << endl;
        if (ok && cur <= t) right = mid;
        else left = mid;
    }
    if (right == n) {
        cout << -1;
        return 0;
    }
    cout << b[right].fi.fi;
    return 0;
}