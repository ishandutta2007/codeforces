#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 1
using lint = long long;

const int M = int(1e9) + 7;

lint cnt[1111111];
lint ans[1111111];
lint p2[1111111];
lint d[1111111];

void solve(istream& cin, ostream& cout) {
    p2[0] = 1;
    rep(i, 1, 1111111) {
        p2[i] = p2[i - 1] * 2 % M;
    }
    memset(ans, 0, sizeof(ans));
    memset(cnt, 0, sizeof(cnt));
    memset(d, 0, sizeof(d));
    int n;
    cin >> n;
    rep(i, 0, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    rep(i, 1, 1111111) {
        for (int j = i; j < 1111111; j += i) {
            d[i] += cnt[j];
        }
    }

    lint ga = 0;

    repr(i, 1111111, 2) {
        if (d[i] == 0) {
            continue;
        }
        lint lc = d[i];
        for (int j = i + i; j < 1111111; j += i) {
            ans[i] -= ans[j];
            ans[i] %= M;
        }
        ans[i] = (ans[i] + lc * p2[lc - 1]) % M;
        ans[i] = (ans[i] + M) % M;
        ga = (ga + ans[i] * i) % M;
    }

    cout << ga;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand(1351551515L);
    for (int ti = 0; ti < 100; ti++) {
        cout << ti << endl;
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
}//aortaj