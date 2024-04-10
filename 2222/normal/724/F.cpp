#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <bitset>
#include <random>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int d, mod;
int F[11][1111][1111];
int inv[11];

int add(int x, int y) { return (x += y) < mod ? x : x - mod; }
int sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }
int mul(int x, int y) { return (ll)x * y % mod; }

int C(int n, int k) {
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res = mul(res, n - i);
        res = mul(res, inv[i + 1]);
    }
    return res;
}

int f(int k, int n, int m) {
    if (m == 0) return k == 0 && n == 0;
    int &res = F[k][n][m];
    if (res < 0) {
        res = f(k, n, m - 1);
        int ways = m == 1 ? 1 : f(d - 1, m - 1, m - 1);
        for (int i = 1; i <= k && i * m <= n; ++i) {
            res = add(res, mul(C(i + ways - 1, i), f(k - i, n - i * m, m - 1)));
        }
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> d >> mod;
    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }
    FOR (i, 1, d + 1) {
        for (int j = 0; ; ++j) {
            if ((1 + (ll)mod * j) % i == 0) {
                inv[i] = (1 + (ll)mod * j) / i;
                break;
            }
        }
    }
    CL(F, -1);
    int res = f(d, n - 1, (n - 1) / 2);
    if (n % 2 == 0) {
        int t = f(d - 1, n / 2 - 1, n / 2 - 1);
        res = add(res, add(C(t, 2), t));
    }
    cout << res << endl;
    return 0;
}