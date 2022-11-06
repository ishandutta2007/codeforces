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

pair<int, int> a[222222];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    int f1 = -1, f2 = -1;
    rep(i, 0, n) {
        if (a[i].first > f1) {
            f1 = a[i].second;
        } else if (a[i].first > f2) {
            f2 = a[i].second;
        } else {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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