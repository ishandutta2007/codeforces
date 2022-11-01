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

int n, m;
int a[22][22];
bool p[22][22][22];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    bool ok = true;
    REP (i, n) {
        int d = 0;
        REP (j, m) {
            cin >> a[i][j], --a[i][j];
            if (a[i][j] != j) ++d;
        }
        if (d > 2) ok = false;
        REP (j1, m) REP (j0, j1) {
            swap(a[i][j0], a[i][j1]);
            vector<int> v;
            REP (j, m) if (a[i][j] != j) v.pb(j);
            if (sz(v) == 0 || sz(v) == 2)
                p[i][j0][j1] = true;
            if (sz(v) == 2)
                p[i][v[0]][v[1]] = true;
            swap(a[i][j0], a[i][j1]);
        }
    }
    if (!ok) {
        REP (j1, m) REP (j0, j1) {
            bool good = true;
            REP (i, n) {
                if (!p[i][j0][j1]) {
                    good = false;
                    break;
                }
            }
            if (good) ok = true;
        }
    }
    puts(ok ? "YES" : "NO");
    return 0;
}