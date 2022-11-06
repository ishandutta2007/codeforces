#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

const int M = int(1e9) + 7;

void add(int& a, lint b) {
    a += b % M;
    if (a >= M) {
        a -= M;
    }
}

int d[55][55][55][55][2];

int p2[55];
int pc[55];
int pd[55];
int c[55][55];
int col[55];

void solve(istream& cin, ostream& cout) {
    c[0][0] = 1;
    rep(i, 1, 55) {
        c[i][0] = 1;
        rep(j, 1, i + 1) {
            add(c[i][j], c[i - 1][j] + c[i - 1][j - 1]);
        }
    }

    p2[0] = 1;
    pc[0] = 0;
    pd[0] = 1;
    rep(i, 1, 55) {
        p2[i] = p2[i - 1] * 1LL * 2 % M;
        for (int j = 0; j <= i; j += 2) {
            add(pd[i], c[i][j]);
        }
        for (int j = 1; j <= i; j += 2) {
            add(pc[i], c[i][j]);
        }
    }

    int n, ap;
    cin >> n >> ap;
    rep(i, 0, n) {
        cin >> col[i];
    }

    if (col[0] != 1) {
        d[0][1][0][0][1] = 1;
    }
    if (col[0] != 0) {
        d[0][0][0][1][1] = 1;
    }

    rep(s, 1, n) {
        rep(b0, 0, s + 1) {
            rep(b1, 0, s + 1) {
                rep(w0, 0, s + 1) {
                    int w1 = s - b0 - b1 - w0;
                    if (w1 < 0) {
                        break;
                    }

                    rep(p, 0, 2) {

                        int cur = d[b0][b1][w0][w1][p];

                        if (col[s] != 0) {
                            add(d[b0][b1][w0 + 1][w1][p], 1LL * p2[b0 + w0 + w1] * pc[b1] % M * cur);
                            add(d[b0][b1][w0][w1 + 1][1 - p], 1LL * p2[b0 + w0 + w1] * pd[b1] % M * cur);
                        }

                        if (col[s] != 1) {
                            add(d[b0 + 1][b1][w0][w1][p], 1LL * p2[b0 + b1 + w0] * pc[w1] % M * cur);
                            add(d[b0][b1 + 1][w0][w1][1 - p], 1LL * p2[b0 + b1 + w0] * pd[w1] % M * cur);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;

    rep(b0, 0, n + 1) {
        rep(b1, 0, n + 1) {
            rep(w0, 0, n + 1) {
                int w1 = n - b0 - b1 - w0;
                if (w1 < 0) {
                    break;
                }
                add(ans, d[b0][b1][w0][w1][ap]);
            }
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
}//fbrvid