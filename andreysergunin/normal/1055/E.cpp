#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

ll intersect(int l1, int r1, int l2, int r2) {
    if (r2 < l1 || r1 < l2) {
        return 0;
    }

    return min(r1, r2) - max(l1, l2) + 1;
}

const int MAXN = 1515;
int dp[MAXN][MAXN];
int pref[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, s, m, k;
    cin >> n >> s >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        r[i] = i - 1;
    }

    for (int i = 0; i < s; ++i) {
        int lf, rg;
        cin >> lf >> rg;
        --lf;
        r[lf] = max(r[lf], rg);
    }

    for (int i = 1; i < n; ++i) {
        r[i] = max(r[i], r[i - 1]);
    }

    vector<int> b = a;
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());

    int lf = -1, rg = sz(b);

    while (rg - lf > 1) {
        int mid = (lf + rg) / 2;

        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + (a[i] <= b[mid] ? 1 : 0);
        }

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n; ++i) {
            if (i > 0) {
                for (int j = 1; j <= m; ++j) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
            }
            if (i < n) {
                int cnt = pref[r[i]] - pref[i];
                for (int j = 0; j <= m; ++j) {
                    dp[r[i]][j + 1] = max(dp[r[i]][j + 1], dp[i][j] + cnt);
                }
            }
        }


        // // cout << b[mid] << endl;
        // // cout << dp[n][m] << endl;
        if (dp[n][m] >= k) {
            rg = mid;
        } else {
            lf = mid;
        }
    }

    if (rg == sz(b)) {
        cout << -1 << endl;
        return 0;
    }

    int res = b[rg];

    cout << res << endl;




}