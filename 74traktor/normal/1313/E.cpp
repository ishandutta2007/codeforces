#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 5e5 + 5;
int good_a[maxn], good_b[maxn], z[3 * maxn];
ll sums[2 * maxn];
ll cntt[2 * maxn];

inline void add(int l, ll x, int y) {
    while (l < 2 * maxn) {
        sums[l] += x;
        cntt[l] += y;
        l = (l|(l + 1));
    }
}

inline int cnt(int l) {
    ll ans = 0;
    while (l >= 0) {
        ans += cntt[l];
        l = (l&(l + 1)) - 1;
    }
    return ans;
}

inline ll sum(int l) {
    ll ans = 0;
    while (l >= 0) {
        ans += sums[l];
        l = (l&(l + 1)) - 1;
    }
    return ans;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, l = 0, r = 0;
    cin >> n >> m;
    string a, b, c, s;
    cin >> a >> b >> c;
    s = c + a;
    for (int i = 1; i < n + m; ++i) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n + m && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    for (int i = m; i < n + m; ++i) {
        good_a[i - m] = min(m - 1, z[i]);
    }
    reverse(b.begin(), b.end()), reverse(c.begin(), c.end());
    s = c + b;
    l = 0, r = 0;
    for (int i = 1; i < n + m; ++i) {
        z[i] = 0;
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n + m && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    for (int i = m; i < n + m; ++i) {
        good_b[n - i + m - 1] = min(m - 1, z[i]);
    }
    ll ans = 0;
    for (int i = 0; i < min(m - 2, n); ++i) {
        add(good_b[i], good_b[i], 1);
    }
    for (int i = 0; i < n; ++i) {
        /*for (int j = i; j < min(n, i + m - 1); ++j) {
            ans += (ll)max(0, good_a[i] - m + 1 + good_b[j]);
        }*/
        int go = i + m - 2;
        if (go < n) add(good_b[go], good_b[go], 1);
        int L = m - 1 - good_a[i];
        //cout << L << " " << cnt(2 * maxn - 1) - cnt(L - 1) << " " << sum(2 * maxn - 1) - sum(L - 1) << endl;
        ans += (ll)(sum(2 * maxn - 1) - sum(L - 1));
        ans += (ll)((good_a[i] + 1 - m) * (ll)(cnt(2 * maxn - 1) - cnt(L - 1)));
        add(good_b[i], -good_b[i], -1);
    }
    cout << ans << '\n';
    return 0;
}