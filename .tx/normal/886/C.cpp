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
int br[222222];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    fill(a, a + n + 1, -1);
    a[0] = 0;
    int x = 1;
    rep(i, 0, n) {
        int t;
        cin >> t;
        if (br[a[t]] != t) {
            a[i + 1] = x++;
        } else {
            a[i + 1] = a[t];
        }
        br[a[i + 1]] = i + 1;
    }
    cout << x;
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