#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

int a[222222];

bool is_sq(int x) {
    int y = int(floor(sqrt(x))) - 1;
    y = max(y, 0);
    while (y * y <= x) {
        if (y * y == x) {
            return true;
        }
        y++;
    }
    return false;
}

int b[222222];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    int csq = 0;
    rep(i, 0, n) {
        cin >> a[i];
        if (is_sq(a[i])) {
            csq++;
        }
    }
    if (csq * 2 == n) {
        cout << 0;
        return;
    }

    vector<int> b;

    if (csq * 2 > n) {
        rep(i, 0, n) {
            if (is_sq(a[i])) {
                if (a[i] == 0) {
                    b.push_back(2);
                } else {
                    b.push_back(1);
                }
            }
        }
        sort(b.rbegin(), b.rend());
        lint ans = 0;
        while (csq * 2 > n) {
            ans += b.back();
            b.pop_back();
            csq--;
        }
        cout << ans;
        return;
    }

    rep(i, 0, n) {
        if (is_sq(a[i])) {
            continue;
        }
        int y = int(floor(sqrt(a[i]))) - 1;
        y = max(y, 0);
        while (y * y <= a[i]) {
            y++;
        }
        int d = min(y * y - a[i], a[i] - (y - 1) * (y - 1));
        b.push_back(d);
    }

    sort(b.rbegin(), b.rend());
    lint ans = 0;
    while (csq * 2 < n) {
        ans += b.back();
        b.pop_back();
        csq++;
    }
    cout << ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}