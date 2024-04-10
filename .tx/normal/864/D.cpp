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

int cnt[222222];
int a[222222];
bool need[222222];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int x = 1;
    int ans = 0;
    rep(i, 0, n) {
        if (cnt[a[i]] > 1) {
            while (cnt[x] != 0) {
                x++;
            }
            if (x < a[i] || need[a[i]]) {
                ans++;
                cnt[a[i]]--;
                cnt[x] = 1;
                a[i] = x;
            } else {
                need[a[i]] = true;
            }
        }
    }
    cout << ans << "\n";
    rep(i, 0, n) {
        cout << a[i] << " ";
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