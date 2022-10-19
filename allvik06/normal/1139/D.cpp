#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

inline int power(int a, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        x >>= 1;
    }
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <vector <int>> all_d(n + 1), all(n + 1);
    for (int i = 2; i <= n; ++i) {
        all_d[i].push_back(1);
        bool pr = all[i].empty();
        for (int j = i; j <= n; j += i) {
            all_d[j].push_back(i);
            if (pr) {
                all[j].push_back(i);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        sort(all[i].begin(), all[i].end());
        all[i].resize(unique(all[i].begin(), all[i].end()) - all[i].begin());
    }
    vector <int> dp(n + 1);
    int n1 = power(n, mod - 2);
    for (int i = 2; i <= n; ++i) {
        int cnti = 0, sp = 0;
        for (int j : all_d[i]) {
            int vali = i / j;
            int cnt = n / j;
            int sum = 0;
            int l = (int)all[vali].size();
            for (int mask = 0; mask < (1 << l); ++mask) {
                int cnt_b = 0, pr = 1;
                for (int k = 0; k < l; ++k) {
                    if ((mask >> k) & 1) {
                        ++cnt_b;
                        pr *= all[vali][k];
                    }
                }
                if (cnt_b & 1) sum -= cnt / pr;
                else sum += cnt / pr;
            }
            if (i == j) cnti = (1 - sum * n1 % mod + mod) % mod;
            else sp = (sp + sum * n1 % mod * dp[j]) % mod;
        }
        dp[i] = (sp + 1) * power(cnti, mod - 2) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + n1 * (dp[i] + 1)) % mod;
    }
    cout << ans;
}

/*

 */