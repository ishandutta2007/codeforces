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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> p(n);
    vector<ll> pref(n + 1);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pref[i + 1] = pref[i] + p[i];
        if (i) {
            ll diff = (100 * p[i] + k - 1) / k;
            ans = max(ans, diff - pref[i]);
            //ans = max(ans, 100 * p[i] - k * pref[i]);
        }
    }
    cout << ans << "\n";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef __SANYA__
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}