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

int p[111111];
bool used[111111];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> p[i];
        --p[i];
    }
    vector<int> ls;
    rep(i, 0, n) {
        if (!used[i]) {
            int c = i;
            int l = 0;
            while (!used[c]) {
                used[c] = true;
                l++;
                c = p[c];
            }
            ls.push_back(l);
        }
    }
    sort(ls.begin(), ls.end());
    if (ls.size() > 1) {
        int x = ls.back();
        ls.pop_back();
        int y = ls.back();
        ls.pop_back();
        ls.push_back(x + y);
    }
    lint ans = 0;
    for (int i : ls) {
        ans += 1LL * i * i;
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