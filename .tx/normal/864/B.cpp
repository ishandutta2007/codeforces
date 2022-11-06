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

int cnt[333];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cd = 0;
    int ans = 0;
    rep(i, 0, n) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            memset(cnt, 0, sizeof(cnt));
            cd = 0;
        } else {
            if (cnt[s[i]]++ == 0) {
                cd++;
            }
        }
        ans = max(ans, cd);
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
}