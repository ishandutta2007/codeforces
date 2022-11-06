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

pair<int, int> xs[1111111];
string ss[111111];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    int mxx = 0;
    rep(i, 0, n) {
        cin >> ss[i];
        int k;
        cin >> k;
        rep(j, 0, k) {
            int x;
            cin >> x;
            --x;
            mxx = max(mxx, x);
            xs[x] = max(xs[x], {ss[i].size(), i});
        }
    }
    int cur = 0;
    string ans = "";
    for (int cur = 0; cur <= mxx; cur++) {
        if (xs[cur].first == 0) {
            if (cur < ans.size()) {
                continue;
            }
            ans.push_back('a');
            continue;
        }

        auto& s = ss[xs[cur].second];
        if (cur + s.size() <= ans.size()) {
            continue;
        }
        rep(i, ans.size() - cur, s.size()) {
            ans.push_back(s[i]);
        }
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