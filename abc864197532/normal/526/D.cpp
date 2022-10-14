#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define test(x) cout << #x << ' ' << x << endl
#define printv(x) { \
    for (auto a : x) cout << a << ' '; \
    cout << endl; \
}
#define pii pair<int, int>
#define pll pair<lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int N = 1000087, abc = 864197532, K = 700, mod = 1e9 + 7;

lli pre[N], pw[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw[0] = 1;
    for (int i = 1; i < N; ++i) pw[i] = pw[i - 1] * abc % mod;
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) pre[i + 1] = (pre[i] * abc + s[i]) % mod;
    auto query = [&](int l, int r) {
        return (pre[r] - pre[l] * pw[r - l] % mod + mod) % mod;
    };
    vector <int> ans(n + 2, 0);
    for (int len = 1; len * k <= n; ++len) {
        lli cur = -1;
        bool is = true;
        for (int i = 0; i < k; ++i) {
            lli d = query(i * len, i * len + len);
            if (cur != -1 && cur != d) is = false;
            cur = d;
        }
        if (is) {
            int l = 0, r = n - k * len + 1;
            while (r - l > 1) {
                int mid = l + r >> 1;
                if (query(0, mid) == query(len * k, len * k + mid)) l = mid;
                else r = mid;
            }
            r = min(r, len + 1);
            ans[k * len]++;
            ans[k * len + r]--;
        }
    }
    for (int i = 0; i < n; ++i) ans[i + 1] += ans[i];
    for (int i = 1; i <= n; ++i) cout << (ans[i] ? 1 : 0);
    cout << endl;
}