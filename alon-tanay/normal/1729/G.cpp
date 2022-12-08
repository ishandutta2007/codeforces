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

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        string a;
        cin >> a;
        string b;
        cin >> b;
        int n = a.length();
        int m = b.length();
        vector<bool> match(n + 1);
        for (int i = 0; i <= n - m; i++) {
            bool fail = false;
            for (int j = 0; j < m; j++) {
                if (a[i + j] != b[j]) {
                    fail = true;
                    break;
                }
            }
            if (!fail) {
                match[i] = true;
            }
        }
        vector<int> nxt(n + 1);
        int cur = n;
        for (int i = n; i >= 0; i--) {
            if (match[i]) {
                cur = i;
            }
            nxt[i] = cur;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[n][0] = 1;
        int lst = n;
        int fst = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (!match[i]) {
                continue;
            }
            lst = i;
            if (fst == -1) {
                fst = i;
            }
            for (int j = i; j < n; j++) {
                if (!match[j]) {
                    continue;
                }
                dp[i][1] += (max(j - i + 1, fst - j + 1) <= m);
            }
            // cout << i << ": ";
            // cout << dp[i][1] << " ";
            for (int k = 2; k <= n; k++) {
                for (int j = i; j < n; j++) {
                    if (i + m <= j) {
                        break;
                    }
                    if (!match[j]) {
                        continue;
                    }
                    dp[i][k] += dp[nxt[min(n, j + m)]][k - 1];
                    dp[i][k] %= MOD;
                }
                // cout << dp[i][k] << " ";
            }
            // cout << endl;
        }
        for (int k = 0; k <= n; k++) {
            if (dp[lst][k]) {
                cout << k << " " << dp[lst][k] << "\n";
                break;
            }
        }
    }
    return 0;
}