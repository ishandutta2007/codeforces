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

int a[2222];
int b[2222];

void solve(istream& cin, ostream& cout) {
    int n, k, p;
    cin >> n >> k >> p;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, k) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + k);
    int ans = 2e9 + 1e8;
    for (int i = 0; i + n <= k; i++) {
        int mx = -1;
        for (int j = 0; j < n; j++) {
            int t = abs(a[j] - b[i + j]) + abs(b[i + j] - p);
            mx = max(mx, t);
        }
        ans = min(ans, mx);
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
}//yjpzei