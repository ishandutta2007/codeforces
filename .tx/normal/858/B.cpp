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

int fs[111];

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    fill(fs, fs + 111, -1);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        fs[x] = y;
    }
    set<int> ans;
    rep(k, 1, 111) {
        bool ok = true;
        rep(i, 0, 111) {
            if (fs[i] != -1 && fs[i] != i / k) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.insert((n - 1) / k);
        }
    }
    if (ans.size() != 1) {
        cout << -1;
    } else {
        cout << (*ans.begin()) + 1;
    }
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