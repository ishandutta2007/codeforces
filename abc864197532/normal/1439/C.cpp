#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 600;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, t, x, y;
    cin >> n >> q;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    vector <vector <int>> block;
    vector <lli> val;
    vector <int> mn, lz;
    fop (i,0,n) {
        if (block.empty() || block.back().size() == K) {
            block.pb({});
            val.pb(0);
            mn.pb(1 << 30);
            lz.pb(-1);
        }
        block.back().pb(a[i]);
        val.back() += a[i];
        mn.back() = min(mn.back(), a[i]);
    }
    int M = block.size();
    while (q--) {
        cin >> t >> x >> y;
        if (t == 1) {
            int cur_len = 0;
            fop (i,0,M) {
                if (cur_len + int(block[i].size()) >= x) {
                    if (~lz[i]) {
                        val[i] = 1ll * lz[i] * int(block[i].size());
                        mn[i] = lz[i];
                        for (int j = 0; j < block[i].size(); ++j) {
                            block[i][j] = lz[i];
                        }
                        lz[i] = -1;
                    }
                    for (int j = 0; j < block[i].size() && cur_len + j < x; ++j) {
                        if (block[i][j] <= y) {
                            val[i] -= block[i][j];
                            block[i][j] = y;
                            val[i] += block[i][j];
                        }
                    }
                    mn[i] = 1 << 30;
                    for (int j = 0; j < block[i].size(); ++j) {
                        mn[i] = min(mn[i], block[i][j]);
                    }
                    break;
                } else {
                    if (~lz[i]) lz[i] = max(lz[i], y), val[i] = 1ll * lz[i] * block[i].size();
                    else {
                        if (block[i][0] <= y) lz[i] = y, val[i] = 1ll * lz[i] * block[i].size();
                        else if (mn[i] <= y) {
                            for (int j = 0; j < block[i].size(); ++j) {
                                if (block[i][j] <= y) {
                                    val[i] -= block[i][j];
                                    block[i][j] = y;
                                    val[i] += block[i][j];
                                }
                            }
                            mn[i] = y;
                        }
                    }
                    cur_len += int(block[i].size());
                }
            }
        } else {
            int cur_len = 0, i, ans = 0;
            for (i = 0; i < block.size(); ++i) {
                if (cur_len + block[i].size() >= x) {
                    if (~lz[i]) {
                        val[i] = 1ll * lz[i] * block[i].size();
                        mn[i] = lz[i];
                        for (int j = 0; j < block[i].size(); ++j) {
                            block[i][j] = lz[i];
                        }
                        lz[i] = -1;
                    }
                    for (int j = 0; j < block[i].size(); ++j) {
                        if (cur_len + j + 1 >= x) {
                            if (y >= block[i][j]) {
                                y -= block[i][j];
                                ans++;
                            }
                        }
                    }
                    i++;
                    break;
                } else {
                    cur_len += block[i].size();
                }
            }
            for (; i < block.size(); ++i) {
                if (y >= val[i]) {
                    y -= val[i];
                    ans += block[i].size();
                } else if (y >= mn[i]) {
                    if (~lz[i]) {
                        val[i] = 1ll * lz[i] * block[i].size();
                        mn[i] = lz[i];
                        for (int j = 0; j < block[i].size(); ++j) {
                            block[i][j] = lz[i];
                        }
                        lz[i] = -1;
                    }
                    for (int j = 0; j < block[i].size(); ++j) {
                        if (y >= block[i][j]) {
                            y -= block[i][j];
                            ans++;
                        }
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}