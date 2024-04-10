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
    int nq;
    cin >> nq;

    vector<int> shift(64);

    auto levelMin = [&](int level) {
        return (1LL << level);
    };

    auto levelMax = [&](int level) {
        return (1LL << (level + 1)) - 1;
    };

    auto isOnLevel = [&](int x, int level) {
        return x >= levelMin(level) && x <= levelMax(level);
    };

    auto makeMod = [&](int& to, int mod) {
        to %= mod;
        if (to < 0) {
            to += mod;
        }
    };

    auto add = [&](int& to, int x, int mod) {
        to += x;
        makeMod(to, mod);
    };

    for (int i = 0; i < nq; ++i) {
        int t, x, k;
        cin >> t;

        int level = 0;

        auto determine = [&]() {
            while (!isOnLevel(x, level)) ++level;
        };

        if (t == 1) {
            cin >> x >> k;
            determine();
            makeMod(k, 1LL << level);
            add(shift[level], k, 1LL << level);
            //cout << "add " << k << " to shift of " << level << "\n";
        }
        else if (t == 2) {
            cin >> x >> k;
            determine();
            //k = -k;
            makeMod(k, 1LL << level);

            for (int lev = level; lev < shift.size(); ++lev) {
                // signed overflow should behave as expected?
                add(shift[lev], (k * (1LL << (lev - level))), 1LL << lev);
            }
        }
        else {
            cin >> x;

            //cout << "query " << x << endl;

            // determine level
            determine();
            x -= levelMin(level);
            x += shift[level];
            makeMod(x, 1LL << level);
            x += levelMin(level);

            while (x) {
                li orig = x;

                x = x - levelMin(level);
                // on pos of x now is
                x -= shift[level];
                //cout << "-= " << shift[level] << endl;
                makeMod(x, 1LL << level);
                x += levelMin(level);
                cout << x << " ";

                x = orig / 2;
                --level;
            }
            cout << "\n";
        }
    }
}