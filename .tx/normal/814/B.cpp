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

int a[1111];
int b[1111];
int cn[1111];
int ans[1111];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        --a[i];
    }
    rep(i, 0, n) {
        cin >> b[i];
        --b[i];
    }

    rep(i, 0, n) {
        memset(cn, 0, sizeof(cn));
        bool ok = true;
        rep(j, 0, n) {
            if (i != j) {
                ans[j] = a[j];
                if (++cn[a[j]] > 1) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            continue;
        }
        rep(j, 0, n) {
            if (cn[j] == 0) {
                ans[i] = j;
                break;
            }
        }
        int cd = 0;
        rep(j, 0, n) {
            if (ans[j] != b[j]) {
                cd++;
            }
        }
        if (cd != 1) {
            continue;
        }
        break;
    }

    rep(i, 0, n) {
        cout << ans[i] + 1 << " ";
    }//
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