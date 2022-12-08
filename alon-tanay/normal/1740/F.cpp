#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT =
#define enl "\n";
#define debug(k)                             \
    for (int _ = 0; _ < DEBUG_INDENT; _++) { \
        cout << "  ";                        \
    }                                        \
    cout << #k << ": " << k << enl;

const int MOD = 998244353;
const ll MODL = 998244353;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int dp[2005][2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }
    sort(as.begin(), as.end());
    as.push_back(-1);
    vector<int> szs;
    int st = 0;
    for (int i = 1; i <= n; i++) {
        if (as[i] != as[i - 1]) {
            szs.push_back(i - st);
            st = i;
        }
    }
    vector<int> bs(n+1);
    for (int i = 0; i <= n; i++) {
        for (int sz : szs) {
            bs[i] += min(sz, i);
        }
    }
    dp[0][0] = 1;
    for (int sz = n; sz >= 1; sz--) {
        for (int i = 1; i <= (n+sz-1)/sz; i++) {
            for (int j = sz; j <= bs[i]; j++) {
                dp[i][j] += dp[i - 1][j - sz];
                dp[i][j] %= MOD;
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= n; i++) {
        if (bs[i] == n) {
            res += dp[i][n];
            res %= MOD;
        }
    }
    cout << res << "\n";
    return 0;
}