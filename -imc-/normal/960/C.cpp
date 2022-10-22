#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    solve(true);

#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - s) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

#define int li

void solve(bool __attribute__((unused)) read) {
    int X, d;
    cin >> X >> d;

    // array of length <= 10^4,
    // elements <= 10^18
    // num nonempty subsequences: max - min < d
    // is equal to X

    int cur = 1;
    vector<int> ans;

    for (int i = 0; i < 31; ++i) {
        if (X & (1 << i)) {
            for (int j = 0; j < i; ++j) {
                ans.push_back(cur);
            }
            cur += d + 1;
            ans.push_back(cur);
            cur += d + 1;
        }
    }

    cout << ans.size() << "\n";
    for (int x: ans)
        cout << x << " ";
    cout << endl;
}