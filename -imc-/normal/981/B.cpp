#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool read);

int main() {
    auto t0 = clock();
#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout.precision(20);
    cout << fixed;

    solve(true);
#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif
}

bool isp(string s) {
    string x = s;
    reverse(all(x));
    return x == s;
}

void solve(bool __attribute__((unused)) read) {
    map<int, int> mx;
    for (int t = 0; t < 2; ++t) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int num, x;
            cin >> num >> x;
            mx[num] = max(mx[num], x);
        }
    }

    li sum = 0;
    for (auto& it: mx) {
        sum += it.second;
    }

    cout << sum << endl;
}