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

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    int p = n;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] >= a[i + 1]) {
            p = i;
            break;
        }
    }
    int q = n;
    for (int i = p; i + 1 < n; i++) {
        if (a[i] != a[i + 1]) {
            q = i;
            break;
        }
    }
    for (int i = q; i + 1 < n; i++) {
        if (a[i] <= a[i + 1]) {
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