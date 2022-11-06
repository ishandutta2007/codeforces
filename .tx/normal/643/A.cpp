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

int a[5555];
int cnt[5555];
int ans[5555];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        --a[i];
    }
    rep(i, 0, n) {
        fill(cnt, cnt + n, 0);
        int mx = 0;
        rep(j, i, n) {
            cnt[a[j]]++;
            if (cnt[a[j]] > cnt[mx] || cnt[a[j]] == cnt[mx] && a[j] < mx) {
                mx = a[j];
            }
            ans[mx]++;
        }
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