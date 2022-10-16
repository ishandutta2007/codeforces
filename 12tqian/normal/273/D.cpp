#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (short i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, T& b) { return a < b ? a = b, 1 : 0; }

const short N = 150;
const int P = 1e9 + 7;

short n, m;

bool g[N][N];
short pre[N][N];

int dp[4][N][N];
int ndp[4][N][N];
int p[4][N][N];

short rect(const short& xl, const short& xr, const short& yl, const short& yr) {
    short res = pre[xr][yr];
    if (xl) res -= pre[xl - 1][yr];
    if (yl) res -= pre[xr][yl - 1];
    if (xl && yl) res += pre[xl - 1][yl - 1];  
    return res;
}

bool full(const short& xl, const short& xr, const short& yl, const short& yr) {
    short num = (yr - yl + 1) * (xr - xl + 1);
    return num == rect(xl, xr, yl, yr);
}

int psum(const short& sl, const short& sr, const short& xl, const short& xr, const short& yl, const short& yr) {
    if (xl > xr) return 0;
    if (yl > yr) return 0;
    auto& pre = p[sl * 2 + sr];
    int res = pre[xr][yr];
    if (xl) {
        res -= pre[xl - 1][yr];
        if (res < 0) res += P;
    }
    if (yl) {
        res -= pre[xr][yl - 1];
        if (res < 0) res += P;
    }
    if (xl && yl) {
        res += pre[xl - 1][yl - 1];  
        if (res >= P) res -= P;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    f0r(i, m) {
        f0r(j, n) {
            g[i][j] = 1;
        }
    }
    f0r(i, m) {
        short run = 0;
        f0r(j, n) {
            run += g[i][j];
            pre[i][j] = run;
            if (i) pre[i][j] += pre[i - 1][j];
        }
    }
    int ans = 0;
    f0r(i, m) {
        f0r(l, n) {
            f1r(r, l, n) {
                if (!full(i, i, l, r)) continue;
                ndp[1 * 2 + 0][l][r] = 1;
                f0r(sl, 2) {
                    f1r(nl, -1, 2) {
                        short ls;
                        if (nl == 0) ls = sl;
                        else if (nl == 1) {
                            if (sl == 0) continue;
                            ls = sl;
                        } else {
                            ls = sl & 0;
                        }
                        f0r(sr, 2) {
                            f1r(nr, -1, 2) {
                                short rs;
                                if (nr == 0) rs = sr;
                                else if (nr == -1) {
                                    if (sr == 1) continue;
                                    rs = sr;
                                } else {
                                    rs = sr | 1;
                                }
                                auto& cur = ndp[2 * ls + rs][l][r];
                                if (nl == 0 && nr == 0) {
                                    cur += dp[2 * sl + sr][l][r];
                                } else if (nl == 0) {
                                    if (nr == -1) {
                                        cur += psum(sl, sr, l, l, 0, r - 1);
                                    } else {
                                        cur += psum(sl, sr, l, l, r + 1, n - 1);
                                    }
                                } else if (nr == 0) {
                                    if (nl == -1) {
                                        cur += psum(sl, sr, 0, l - 1, r, r);
                                    } else {
                                        cur += psum(sl, sr, l + 1, n - 1, r, r);
                                    }
                                } else {    
                                    if (nl == -1 && nr == -1) {
                                        cur += psum(sl, sr, 0, l - 1, l, r - 1);
                                    } else if (nl == -1 && nr == 1) {
                                        cur += psum(sl, sr, 0, l - 1, r + 1, n - 1);
                                    } else if (nl == 1 && nr == -1) {
                                        cur += psum(sl, sr, l + 1, r - 1, l + 1, r - 1);
                                    } else if (nl == 1 && nr == 1) {
                                        cur += psum(sl, sr, l + 1, r, r + 1, n - 1);
                                    }
                                }
                                if (cur >= P) cur -= P;
                            }
                        }
                    }
                }
            }
        }
        f0r(sl, 2) {
            f0r(sr, 2) {
                f0r(l, n) {
                    int run = 0;
                    f0r(r, n) {
                        ans += ndp[sl * 2 + sr][l][r];
                        if (ans >= P) ans -= P;
                        dp[sl * 2 + sr][l][r] = ndp[sl * 2 + sr][l][r];
                        ndp[sl * 2 + sr][l][r] = 0;
                        run += dp[sl * 2 + sr][l][r];
                        if (run >= P) run -= P;
                        p[sl * 2 + sr][l][r] = run;
                        if (l) {
                            p[sl * 2 + sr][l][r] += p[sl * 2 + sr][l - 1][r];
                            if (p[sl * 2 + sr][l][r] >= P) p[sl * 2 + sr][l][r] -= P;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}