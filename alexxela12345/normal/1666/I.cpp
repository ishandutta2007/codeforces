#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

int ask(int a, int b) {
    cout << "SCAN " << a + 1<< " " << b + 1 << endl;
    int x;
    cin >> x;
    return x;
}

bool dig(int a, int b) {
    cout << "DIG " << a + 1 << " " << b + 1 << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int lu = ask(0, 0);
    int ru = ask(0, m - 1);
    int sumx = (lu + ru - 2 * m + 2) / 2;
    int sumy = lu - sumx;
    int xa = sumx / 2;
    int ya = sumy / 2;
    int f = ask(xa, ya);
    int f2 = ask(xa, 0);
    int y1 = (f2 - f) / 2;
    int y2 = sumy - y1;
    int x1 = (lu - f2) / 2;
    int x2 = sumx - x1;
    if (dig(x1, y1)) {
        assert(dig(x2, y2));
        return;
    }
    dig(x1, y2);
    dig(x2, y1);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}