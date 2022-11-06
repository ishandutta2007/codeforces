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

int c[333333];
int ans[333333];

void solve(istream& cin, ostream& cout) {
    int n, k;
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> c[i];
    }
    lint s = 0;
    lint cc = 0;
    priority_queue<pair<int, int>> q;
    rep(i, 0, k) {
        cc += c[i];
        s += cc;
        q.push({c[i], i});
    }

    rep(i, k, k + n) {
        if (i < n) {
            q.push({c[i], i});
            cc += c[i];
        }
        auto v = q.top();
        q.pop();
        cc -= v.first;
        ans[v.second] = i;
        s += cc;
    }
    cout << s << "\n";
    rep(i, 0, n) {
        cout << ans[i] + 1 << " ";
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