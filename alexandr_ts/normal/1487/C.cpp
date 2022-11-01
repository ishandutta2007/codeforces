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

void solve(int n) {
    if (n % 2 == 1) {
        for (int i = 0; i < n * (n - 1) / 2; ++i) {
            if (i % 2 == 0) {
                cout << 1 << " ";
            } else {
                cout << -1 << " ";
            }
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i % 2 == 0 && j == i + 1) {
                cout << 0 << " ";
                continue;
            }
            if ((i + j) % 2) {
                cout << "1 ";
            } else {
                cout << "-1 ";
            }
        }
    }
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
        int n;
        cin >> n;
        solve(n);
        cout << "\n";
    }
    return 0;
}