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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> p(n), s(n);
    REP (i, n) cin >> p[i];
    REP (i, n) cin >> s[i];
    vector<ll> f(1);
    REP (i, n) {
        vector<ll> g(i + 2, -1ull/2);
        for (int j = 0; j <= i; ++j) {
            g[j + 1] = min(g[j + 1], f[j] + s[i]);
            g[j] = min(g[j], f[j] + p[i] + (ll)j * c);
        }
        swap(f, g);
    }
    cout << *min_element(all(f)) << endl;
    return 0;
}