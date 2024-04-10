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

int bx[222222];
int c[222222];
int d[222222];

void solve(istream& cin, ostream& cout) {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> ps;
    rep(i, 0, n) {
        int l, r, cc;
        cin >> l >> r >> cc;
        --l; --r;
        c[i] = cc;
        d[i] = r - l + 1;
        if (d[i] >= x) {
            continue;
        }
        ps.push_back({l, -i - 1});
        ps.push_back({r, i});
    }
    sort(ps.begin(), ps.end());
    fill(bx, bx + 222222, -1);
    int ans = int(2e9) + 1e8;
    for (auto& p : ps) {
        int t = p.first;
        int id = p.second;
        if (id >= 0) {
            if (bx[d[id]] == -1) {
                bx[d[id]] = 2e9;
            }
            bx[d[id]] = min(bx[d[id]], c[id]);
        } else {
            id = -id - 1;
            if (bx[x - d[id]] != -1) {
                ans = min(ans, c[id] + bx[x - d[id]]);
            }
        }
    }
    if (ans > 2e9) {
        cout << -1;
    } else {
        cout << ans;
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