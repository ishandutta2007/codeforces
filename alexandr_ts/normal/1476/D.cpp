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
const char L = 'L';
const char R = 'R';

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> l(n + 1), r(n + 1);
    for (int pad = 0; pad <= 1; ++pad) {
        for (int i = pad; i <= n; i += 2) {
            l[i] = i;
            if (i > 1) {
                if (s[i - 1] == L && s[i - 2] == R) {
                    l[i] = l[i - 2];
                }
            }
            if (i > 0 && s[i - 1] == L) {
                l[i] = min(l[i], i - 1);
            }
        }

        for (int i = n - pad; i >= 0; i -= 2) {
            r[i] = i;
            if (i + 2 <= n) {
                if (s[i] == R && s[i + 1] == L) {
                    r[i] = r[i + 2];
                }
            }
            if (i + 1 <= n && s[i] == R) {
                r[i] = max(r[i], i + 1);
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        cout << r[i] - l[i] + 1 << " ";
    }
    cout << "\n";
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
    while (t--) {
        solve();
    }

    return 0;
}