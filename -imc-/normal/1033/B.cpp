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
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
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

//#define int li
//const int mod = 1000000007;

struct point {
    int x, y;
};

bool attacked(point a, point b) {
    int dx = abs(a.x - b.x), dy = abs(a.y - b.y);
    return dx == 0 || dy == 0 || dx == dy;
}

bool isPrime(li x) {
    for (li y = 2; y * y <= x; ++y) {
        if (x % y == 0) {
            return false;
        }
    }

    return true;
}

void solve(__attribute__((unused)) bool read) {
    int nt;
    cin >> nt;

    for (int i = 0; i < nt; ++i) {
        li a, b;
        cin >> a >> b;

        if (b + 1 != a) {
            cout << "NO\n";
            continue;
        }

        cout << (isPrime(a + b) ? "YES" : "NO") << "\n";
    }
}