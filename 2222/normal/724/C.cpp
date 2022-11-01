#include <algorithm>
#include <iostream>
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

int gcd(int x, int y) {
    for (; y; swap(x %= y, y));
    return x;
}

int inv(int x, int mod) {  // x < mod
  return x < 2 ? x : mod - static_cast<long long>(inv(mod % x, x)) * mod / x;
}

ll crt(int x, int y, int n, int m) {
    int d = (y - x) % m;
    if (d < 0) d += m;
    int g = gcd(n, m);
    if (d % g) return -1;
    d /= g;
    int ng = n / g;
    int mg = m / g;
    ll k = (ll)inv(ng % mg, mg) * d % mg;
    return x + k * n;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    n *= 2;
    m *= 2;
    REP (i, k) {
        int x, y;
        cin >> x >> y;
        ll bestT = -1;
        REP (v, 2) REP (w, 2) {
            ll t = crt(v ? x : n - x, w ? y : m - y, n, m);
            if (bestT < 0 || (t >= 0 && t < bestT)) bestT = t;
        }
        cout << bestT << endl;
    }
    return 0;
}