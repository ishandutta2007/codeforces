#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h, m, k;
    cin >> n >> h >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y >= m / 2) y -= m / 2;
        a[i] = y;
    }
    vector<pii> b;
    for (auto &c : a) {
        if (c + k < m / 2) b.pb(c + k, m / 2 - 1);
        int l = max(0, k - (m / 2 - c)), r = c;
        if (l > r) continue;
        b.pb(l, r);
    }
    vector<pii> e;
    for (auto &c : b) {
        e.pb(c.fi, 0);
        e.pb(c.se, 1);
    }
    sort(all(e));
    int ans = n, t = 0;
    int bal = 0;
    for (auto &c : e) {
        if (c.se == 0) bal++;
        else bal--;
        if (n - bal < ans) {
            ans = n - bal;
            t = c.fi;
        }
    }
    cout << ans << " " << t << "\n";
    vector<int> del;
    for (int i = 0; i < n; i++) {
        if ((t > a[i] && t < a[i] + k) || (t <= a[i] && t + m / 2 - k < a[i])) del.pb(i);
    }
    for (auto &c : del) cout << c + 1 << " ";
    return 0;
}