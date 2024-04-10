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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int MAXN = 1e5 + 100;
const int MAXK = 20;

ll f[11][64][1 << 10];

void precalc() {
    for (int n = 2; n <= 10; ++n) {
        f[n][0][0] = 1;
        for (int len = 0; len < 63; ++len) {
            for (int mask = 0; mask < (1 << n); ++mask) {
                for (int d = 0; d < n; ++d) {
                    f[n][len + 1][mask ^ (1 << d)] += f[n][len][mask];
                }
            }
                
        }
    }
}

ll solve(int n, ll l) {
    if (l <= 0)
        return 0;

    vector<int> d;
    for (; l > 0; l /= n) {
        d.push_back(l % n);
    }
    reverse(all(d));

    ll ans = 0;

    for (int i = 1; i < sz(d); ++i) {
        ans += f[n][i][0] - f[n][i - 1][0 ^ 1];
    }

    int cur = 0;

    for (int i = 0; i < sz(d); ++i) {
        for (int j = (i == 0 ? 1 : 0); j < d[i]; ++j) {
            ans += f[n][sz(d) - i - 1][cur ^ (1 << j)];
        }
        cur ^= (1 << d[i]);
    }
    ans += (cur == 0);
    return ans;
}

int main() {
    //freopen("comb.in", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    precalc();

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int n;
        ll l, r;
        cin >> n >> l >> r;
        cout << solve(n, r) - solve(n, l - 1) << endl;
    }

}