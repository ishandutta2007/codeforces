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

void solve(istream& cin, ostream& cout) {
    int n, k;
    cin >> n >> k;
    int c4 = n;
    int c2 = 2 * n;
    int c1 = 0;
    int s = 0;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        while (x >= 4 && c4 > 0) {
            x -= 4;
            c4 -= 1;
        }
        while (x >= 4 && c2 >= 2) {
            x -= 4;
            c2 -= 2;
        }
        while (x >= 4 && c1 > 0) {
            x--;
            c1--;
        }
        if (x >= 4) {
            cout << "NO";
            return;
        }
        if (x == 3 && c4 > 0) {
            x = 0;
            c4--;
        } else if (x == 3 && c4 == 0) {
            if (c2 >= 2) {
                c2 -= 2;
                x = 0;
            } else if (c2 > 0) {
                c2--;
                x = 1;
            }
            }
        if (x == 2) {
            if (c2 > 0) {
                c2--;
                x = 0;
            } else if (c4 > 0) {
                c4--;
                c1++;
                x = 0;
            }
        } else if (x == 1) {
            if (c1 > 0) {
                c1--;
                x = 0;
                continue;
            }
            if (c2 == 0 && c4 == 0) {
                cout << "NO";
                return;
            }
            if (c4 > 0) {
                c4--;
                c2++;
                x = 0;
            } else {
                c2--;
                x = 0;
            }
        }


        if (x <= c1) {
            c1 -= x;
            x = 0;
        }

        if (x != 0) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
}//kek