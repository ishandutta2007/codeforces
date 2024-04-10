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

lint d[2][55][55][55][55];
int a[55];

const int M = (int) 1e9 + 7;

void add(lint& a, lint b) {
    a = (a + b) % M;
}

void calc_mults(lint& t, int cnt, int val) {
    if (cnt > 0) {
        t *= val;
    }
    if (cnt > 1) {
        t = t * (val - 1) / 2;
    }
    if (cnt > 2) {
        t = t * (val - 2) / 3;
    }
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }

    d[0][a[0] == 2 ? 1 : 0][a[0] == 3 ? 1 : 0][a[1] == 2 ? 1 : 0][a[1] == 3 ? 1 : 0] = 1;
    rep(i, 2, n) {
        int cr = i & 1;
        int nx = cr ^ 1;
        rep(i1, 0, 55) rep(i2, 0, 55) rep(i3, 0, 55) rep(i4, 0, 55) d[nx][i1][i2][i3][i4] = 0;
        rep(p1, 0, n) {
            rep(p2, 0, n) {
                rep(c1, 0, n) {
                    rep(c2, 0, n) {
                        lint t = d[cr][p1][p2][c1][c2];
                        if (t == 0) {
                            continue;
                        }
                        if (p1 + p2 == 0) {
                            add(d[cr][c1][c2][0][0], t);
                            continue;
                        }
                        for (int tp1 = 0; tp1 <= p1 && tp1 <= a[i]; tp1++) {
                            for (int tp2 = 0; tp2 <= p2 && tp2 + tp1 <= a[i]; tp2++) {
                                if (tp1 + tp2 != 1) {
                                    continue;
                                }
                                for (int tc1 = 0; tc1 <= c1 && tc1 + tp1 + tp2 <= a[i]; tc1++) {
                                    for (int tc2 = 0; tc2 <= c2 && tc2 + tc1 + tp1 + tp2 <= a[i]; tc2++) {
                                        int rem = a[i] - tp1 - tp2 - tc1 - tc2;
                                        lint nt = t;
                                        calc_mults(nt, tp1, p1);
                                        calc_mults(nt, tp2, p2);
                                        calc_mults(nt, tc1, c1);
                                        calc_mults(nt, tc2, c2);
                                        int np1 = p1 - tp1 + tp2;
                                        int np2 = p2 - tp2;
                                        int nc1 = c1 - tc1 + tc2;
                                        int nc2 = c2 - tc2;
                                        if (rem == 1) {
                                            nc1++;
                                        } else if (rem == 2) {
                                            nc2++;
                                        }
                                        add(d[nx][np1][np2][nc1][nc2], nt);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << d[n & 1][0][0][0][0];
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
}//crwwjc