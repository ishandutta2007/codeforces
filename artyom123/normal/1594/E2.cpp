#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double

const long long INFLL = 1e18;
const int INF = 1e9 + 5;
const int mod = 1e9 + 7;

int get_lvl(ll v) {
    int ans = 0;
    while (v) {
        ans++;
        v /= 2;
    }
    return ans;
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<int> col(n);
    unordered_map<ll, int> id;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        id[v[i]] = i;
        string s;
        cin >> s;
        if (s[0] == 'w') col[i] = 0;
        if (s[0] == 'y') col[i] = 1;
        if (s[0] == 'g') col[i] = 2;
        if (s[0] == 'b') col[i] = 3;
        if (s[0] == 'r') col[i] = 4;
        if (s[0] == 'o') col[i] = 5;
    }
    vector<set<ll>> lvl(k + 1);
    for (auto &c : v) {
        int cur = get_lvl(c);
        while (cur > 0) {
            lvl[k - cur + 1].insert(c);
            cur--;
            c /= 2;
        }
    }
    unordered_map<ll, int> kek;
    for (int i = 1; i <= k; i++) {
        int l = 1;
        for (auto &v : lvl[i]) {
            kek[v] = l++;
        }
    }
    vector<vector<vector<ll>>> dp(k + 1, vector<vector<ll>>(6));
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 6; j++) dp[i][j].resize(lvl[i].size() + 1);
    }
    for (int j = 0; j < 6; j++) dp[1][j][0] = 1;
    int l = 1;
    for (auto &v : lvl[1]) {
        dp[1][col[id[v]]][l] = 1;
        l++;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < 6; j++) {
            dp[i][j][0] = (16 * ((dp[i - 1][j][0] * dp[i - 1][j][0]) % mod)) % mod;
            int l = 1;
            for (auto &v : lvl[i]) {
                if (id.count(v)) {
                    if (j != col[id[v]]) {
                        l++;
                        continue;
                    }
                }
                for (int j1 = 0; j1 < 6; j1++) {
                    if ((j ^ j1) <= 1) continue;
                    for (int j2 = 0; j2 < 6; j2++) {
                        if ((j ^ j2) <= 1) continue;
                        ll res1 = dp[i - 1][j1][0];
                        ll res2 = dp[i - 1][j2][0];
                        if (kek.count(2 * v)) res1 = dp[i - 1][j1][kek[2 * v]];
                        if (kek.count(2 * v + 1)) res2 = dp[i - 1][j2][kek[2 * v + 1]];
                        dp[i][j][l] += res1 * res2;
                        dp[i][j][l] %= mod;
                    }
                }
                l++;
            }
        }
    }
    ll ans = 0;
    if (n == 0) ans = (6 * dp[k][0][0]) % mod;
    else {
        for (int j = 0; j < 6; j++) {
            ans += dp[k][j][1];
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}