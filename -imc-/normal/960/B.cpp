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
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    multiset<int> deltas;
    for (int i = 0; i < n; ++i) {
        deltas.insert(abs(a[i] - b[i]));
    }

    int ops = k1 + k2;

    while (ops) {
        --ops;

        auto it = prev(deltas.end());
        int num = *it;
        deltas.erase(it);
        if (!num) {
            num = 1;
        }
        else {
            num--;
        }
        deltas.insert(num);
    }

    li err = 0;
    for (auto it: deltas) {
        err += it * (li)it;
    }

    cout << err << endl;
};