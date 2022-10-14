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

ll solve(ll x, ll k, ll y, vector<int> &a) {
    /*
    for (auto &c : a) cout << c << " ";
    cout << endl;
    */
    ll ans = 0;
    int n = a.size();
    if (k * y < x) {
        int mx = 0;
        for (int i = 1; i < (int)a.size() - 1; i++) mx = max(mx, a[i]);
        if (n - 2 < k && mx > max(a[0], a[n - 1])) return -1;
        if (mx > max(a[0], a[n - 1])) ans = x + (n - 2 - k) * y;
        else ans = (n - 2) * y;
    } else {
        int cnt = (n - 2) / k;
        int now = 0;
        vector<int> pos;
        for (int i = 1; i < (int)a.size() - 1; i++) {
            if (a[i] > max(a[0], a[n - 1])) pos.pb(i);
        }
        for (int i = 0; i < (int)pos.size(); i++) {
            now++;
            int j = i;
            while (j < (int)pos.size() && pos[j] < pos[i] + k) j++;
            i = j - 1;
        }
        if (now > cnt) return -1;
        else ans = cnt * x + ((n - 2) % k) * y;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll x, k, y;
    cin >> x >> k >> y;
    vector<int> a(n), b(m);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    vector<int> ind;
    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (a[i] == b[j]) {
            ind.pb(i);
            j++;
        }
    }
    if ((int)ind.size() < m) {
        cout << -1;
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < m - 1; i++) {
        vector<int> now;
        for (int l = ind[i]; l <= ind[i + 1]; l++) now.pb(a[l]);
        ll tmp = solve(x, k, y, now);
        if (tmp == -1) {
            cout << -1;
            return 0;
        }
        ans += tmp;
    }
    if (ind[0] > 0) {
        vector<int> now;
        now.pb(-1);
        for (int l = 0; l <= ind[0]; l++) now.pb(a[l]);
        ll tmp = solve(x, k, y, now);
        if (tmp == -1) {
            cout << -1;
            return 0;
        }
        ans += tmp;
    }
    if (ind[m - 1] < n - 1) {
        vector<int> now;
        for (int l = ind[m - 1]; l <= n - 1; l++) now.pb(a[l]);
        now.pb(-1);
        ll tmp = solve(x, k, y, now);
        if (tmp == -1) {
            cout << -1;
            return 0;
        }
        ans += tmp;
    }
    cout << ans;
    return 0;
}