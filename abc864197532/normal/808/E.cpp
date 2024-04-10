#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17;

struct item {
    long long v;
    int o, t;
    item (int a) {
        if (a == 1) v = -1ll << 60, o = t = 0;
        else v = o = t = 0;
    }
    item (long long _v, int a, int b) : v(_v), o(a), t(b) {}
    bool operator < (const item &A) {
        return v < A.v;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector <int> a[4];
    for (int i = 0, w, v; i < n; ++i) {
        cin >> w >> v;
        a[w].pb(v);
    }
    for (int i : {1, 2, 3}) sort(rall(a[i]));
    vector <item> dp(w + 1, item(0));
    for (int i = 1; i <= w; ++i) {
        if (i == 1) {
            dp[i] = (!a[1].empty() ? item(dp[0].v + a[1][0], dp[0].o + 1, dp[0].t) : item(1));
        } else {
            item A = item(1);
            if (dp[i - 2].t < a[2].size()) A = item(dp[i - 2].v + a[2][dp[i - 2].t], dp[i - 2].o, dp[i - 2].t + 1);
            item B = item(1);
            if (dp[i - 1].o < a[1].size()) B = item(dp[i - 1].v + a[1][dp[i - 1].o], dp[i - 1].o + 1, dp[i - 1].t);
            dp[i] = (A < B ? B : A);
        }
    }
    for (int i = 1; i <= w; ++i) {
        if (dp[i] < dp[i - 1]) dp[i] = dp[i - 1];
    }
    lli pre = 0, ans = 0;
    for (int i = 0; i <= a[3].size() && w >= 3 * i; ++i) {
        if (i) pre += a[3][i - 1];
        ans = max(ans, pre + dp[w - 3 * i].v);
    }
    cout << ans << endl;
}