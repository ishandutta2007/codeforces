#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui32 = unsigned int;
constexpr ll INFLL = 1e18;

#define CHECK_IMPL1(cond)              \
if (!(cond)) {                         \
    DEBUG("expected cond: " << #cond); \
    assert(cond);                      \
}

#define CHECK_IMPL2(cond, message)                                            \
if (!(cond)) {                                                                \
    DEBUG("expected cond: " << #cond << " failed with message: " << message); \
    assert(cond);                                                             \
}
#define CHECK_IMPL(_1, _2, NAME, ...) NAME
#define CHECK(...) CHECK_IMPL(__VA_ARGS__, CHECK_IMPL2, CHECK_IMPL1, CHECK_IMPL0)(__VA_ARGS__)

#ifdef __SANYA__
#define DEBUG(message) std::cerr << message << std::endl;
#else
#define DEBUG(message)
#endif

const ll INF = 1e15;

void solve() {
    vector<int> n(4);
    for (int i = 0; i < 4; ++i) {
        cin >> n[i];
    }
    vector<vector<pair<ll, int>>> a(4);
    for (int i = 0; i < 4; ++i) {
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; ++j) {
            cin >> a[i][j].first;
            a[i][j].second = j;
        }
        sort(a[i].begin(), a[i].end());
    }

    vector<int> m(3);

    vector<ll> best1(n[1], INF);
    vector<ll> best2(n[2], INF);

    vector<set<int>> bad1(n[1]);
    vector<set<int>> bad2(n[2]);

    cin >> m[0];
    for (int i = 0; i < m[0]; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        bad1[y].insert(x);
    }

    vector<set<int>>bad_mid(n[1]);
    cin >> m[1];
    for (int i = 0; i < m[1]; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        bad_mid[x].insert(y);
    }

    cin >> m[2];
    for (int i = 0; i < m[2]; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        bad2[x].insert(y);
    }

    vector<ll> val1(n[1], INF);
    vector<ll> val2(n[2], INF);

    for (int i = 0; i < n[1]; ++i) {
        for (int j = 0; j < n[0]; ++j) {
            if (!bad1[a[1][i].second].count(a[0][j].second)) {
                val1[a[1][i].second] = a[1][i].first + a[0][j].first;
                break;
            }
        }
    }

    for (int i = 0; i < n[2]; ++i) {
        for(int j = 0; j < n[3]; ++j) {
            if (!bad2[a[2][i].second].count(a[3][j].second)) {
                val2[a[2][i].second] = a[2][i].first + a[3][j].first;
                break;
            }
        }
    }

   // for (int i = 0; i < n[1]; ++i) cout << val1[i] << " ";cout << endl;
    //for (int i = 0; i < n[2]; ++i) cout << val2[i] << " ";cout << endl;

    for (int j = 1; j <= 2; ++j) {
        for (int i = 0; i < n[j]; ++i) {
            if (j == 1) {
                a[j][i].first = val1[a[j][i].second];
            } else {
                a[j][i].first = val2[a[j][i].second];
            }
        }
        sort(a[j].begin(), a[j].end());
    }

    ll ans = INF;
    for (int i = 0; i < n[1]; ++i) {
        ll val = INF;
        for (int j = 0; j < n[2]; ++j) {
            if (!bad_mid[a[1][i].second].count(a[2][j].second)) {
                val = a[1][i].first + a[2][j].first;
                break;
            }
        }
        ans = min(ans, val);
    }
    if (ans >= INF) {
        ans = -1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef __SANYA__
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    solve();
    return 0;
}