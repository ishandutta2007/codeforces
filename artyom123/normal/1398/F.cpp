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

vector<int> p, mx;

int get_par(int v) {
    if (p[v] == v) return v;
    return p[v] = get_par(p[v]);
}

void merge(int v, int u) {
    v = get_par(v);
    u = get_par(u);
    if (v == u) return;
    p[u] = v;
    mx[v] = max(mx[v], mx[u]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pii> a(n);
    vector<int> dp(n);
    int pos0 = n, pos1 = n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') pos0 = i;
        else if (s[i] == '1') pos1 = i;
        if (s[i] == '0') a[i] = {pos1 - i, i};
        else if (s[i] == '1') a[i] = {pos0 - i, i};
        else a[i] = {max(pos1, pos0) - i, i};
        dp[i] = a[i].fi;
    }
    sort(all(a));
    p.resize(n + 1); mx.resize(n + 1);
    iota(all(p), 0); iota(all(mx), 0);
    int l = 0;
    for (int x = 1; x <= n; x++) {
        while (l < (int)a.size() && a[l].fi < x) {
            merge(a[l].se, a[l].se + 1);
            l++;
        }
        int ans = 0, pos = 0;
        while (pos < n) {
            pos = mx[get_par(pos)];
            if (pos >= n) break;
            ans++;
            pos += x;
        }
        cout << ans << " ";
    }
    return 0;
}