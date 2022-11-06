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

lint d[22][222][3][3];

vector<int> td(lint x) {
    vector<int> res;
    do {
        res.push_back(x % 10);
        x /= 10;
    } while (x);
    reverse(res.begin(), res.end());
    return res;
}

void solve(istream& cin, ostream& cout) {
    lint n, s;
    cin >> n >> s;
    n++;
    vector<int> nd = td(n);
    lint ans = 0;
    rep(fi, 1, 9 * nd.size() + 1) {
        vector<int> sd = td(s + fi);
        memset(d, 0, sizeof(lint) * 22 * 222 * 3 * 3);
        d[0][0][0][0] = 1;
        int m = min(nd.size(), sd.size());
        if (fi == 2) {
            fi++;
            fi -= 1;
        }
        rep(i, 1, m + 1) {
            rep(f, 0, 9 * i + 1) {
                rep(c, 0, min(9, f) + 1) {
                    d[i][f][1][1] += d[i - 1][f - c][1][1];
                    if (c < nd[i - 1]) {
                        d[i][f][1][1] += d[i - 1][f - c][0][1];
                    }
                    if (c < sd[i - 1]) {
                        d[i][f][1][1] += d[i - 1][f - c][1][0];
                    }
                    if (c < nd[i - 1] && c < sd[i - 1]) {
                        d[i][f][1][1] += d[i - 1][f - c][0][0];
                    }
                    d[i][f][2][2] += d[i - 1][f - c][2][2];
                    if (c > nd[i - 1]) {
                        d[i][f][2][2] += d[i - 1][f - c][0][2];
                    }
                    if (c > sd[i - 1]) {
                        d[i][f][2][2] += d[i - 1][f - c][2][0];
                    }
                    if (c > nd[i - 1] && c > sd[i - 1]) {
                        d[i][f][2][2] += d[i - 1][f - c][0][0];
                    }
                    if (c == nd[i - 1]) {
                        d[i][f][0][1] += d[i - 1][f - c][0][1];
                        if (c < sd[i - 1]) {
                            d[i][f][0][1] += d[i - 1][f - c][0][0];
                        }
                        d[i][f][0][2] += d[i - 1][f - c][0][2];
                        if (c > sd[i - 1]) {
                            d[i][f][0][2] += d[i - 1][f - c][0][0];
                        }
                    }
                    if (c == sd[i - 1]) {
                        d[i][f][1][0] += d[i - 1][f - c][1][0];
                        if (c < nd[i - 1]) {
                            d[i][f][1][0] += d[i - 1][f - c][0][0];
                        }
                        d[i][f][2][0] += d[i - 1][f - c][2][0];
                        if (c > nd[i - 1]) {
                            d[i][f][2][0] += d[i - 1][f - c][0][0];
                        }
                    }
                    if (c == nd[i - 1] && c == sd[i - 1]) {
                        d[i][f][0][0] += d[i - 1][f - c][0][0];
                    }
                    d[i][f][2][1] += d[i - 1][f - c][2][1];
                    if (c > nd[i - 1]) {
                        d[i][f][2][1] += d[i - 1][f - c][0][1];
                        if (c < sd[i - 1]) {
                            d[i][f][2][1] += d[i - 1][f - c][0][0];
                        }
                    }
                    if (c < sd[i - 1]) {
                        d[i][f][2][1] += d[i - 1][f - c][2][0];
                    }

                    d[i][f][1][2] += d[i - 1][f - c][1][2];
                    if (c > sd[i - 1]) {
                        d[i][f][1][2] += d[i - 1][f - c][1][0];
                        if (c < nd[i - 1]) {
                            d[i][f][1][2] += d[i - 1][f - c][0][0];
                        }
                    }
                    if (c < nd[i - 1]) {
                        d[i][f][1][2] += d[i - 1][f - c][0][2];
                    }
                }
            }
        }
        lint lans = ans;
        ans += d[m][fi][1][1];
        if (nd.size() > m) {
            ans += d[m][fi][0][1];
            ans += d[m][fi][2][1];
        }
        if (sd.size() > m) {
            ans += d[m][fi][1][0];
            ans += d[m][fi][1][2];
        }
//        cerr << fi << " " << fi + s << " " << ans - lans << endl;
    }

    cout << n - 1 - ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand(3298488);
    for (int ti = 0; ti < 10000; ti++) {
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
}//yltynw