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

pair<int, int> a[111];
int ans[111];

void solve(istream& cin, ostream& cout) {
    int n, w;
    cin >> n >> w;
    rep(i, 0, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    rep(i, 0, n) {
        int t = (a[i].first + 1) / 2;
        w -= t;
        ans[a[i].second] = t;
    }
    if (w < 0) {
        cout << -1;
        return;
    }
    repr(i, n, 0) {
        int t = a[i].first - ans[a[i].second];
        t = min(w, t);
        ans[a[i].second] += t;
        w -= t;
    }

    rep(i, 0, n) {
        cout << ans[i] << " ";
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