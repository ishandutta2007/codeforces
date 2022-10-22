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

vector<vector<int>> to;
vector<int> win;

int getWin(int x) {
    if (win[x] != -1) {
        return win[x];
    }

    for (int y : to[x]) {
        if (getWin(y) == 1) {
            return win[x] = 0;
        }
    }

    return win[x] = 1;
}

void solve(__attribute__((unused)) bool read) {
    int n;
    cin >> n;

    win.assign(n, -1);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    to.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int now = i - a[i]; now >= 0; now -= a[i]) {
            if (a[now] > a[i]) {
                to[i].push_back(now);
            }
        }
        for (int now = i + a[i]; now < n; now += a[i]) {
            if (a[now] > a[i]) {
                to[i].push_back(now);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << (getWin(i) == 0 ? 'A' : 'B');
    }
    cout << "\n";
}