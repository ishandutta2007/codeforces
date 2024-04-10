#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }


const int MOD = 998244353;

void addmod(int& x, const int d) {
    x += d;
    if (x >= MOD) {
        x -= MOD;
    }
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    string s;
    while (cin >> s) {
        int n = s.size();
        if (s[n - 1] == '1') {
            cout << 0 << endl;
            continue;
        }

        vector<vector<int>> upd(2, vector<int>(n, 0));
        vector<vector<int>> val(2, vector<int>(n, 0));
        int cnt = 0;

        int answer = 0;
        for (int m = 1; m < n; ++m) {
            vector<vector<int>> flg(2, vector<int>(n, false));

            int res = 1;
            for (int col = 0; col < n; ++col) {
                for (int row = 0; row < 2; ++row) {
                    if (!flg[row][col]) {
                        int delta = res;
                        res = 0;
                        for (int v = 0; v < 2; ++v) {
                            bool ok = true;

                            ++cnt;
                            upd[0][n - 1] = upd[1][n - 1] = cnt;
                            val[0][n - 1] = val[1][n - 1] = 1;

                            upd[row][col] = cnt;
                            val[row][col] = v;
                            queue<pair<int, int>> q;
                            q.push({row, col});


                            auto push = [&](int r, int c, int v) {
                                if (upd[r][c] != cnt) {
                                    upd[r][c] = cnt;
                                    val[r][c] = v;
                                    q.push({r, c});
                                } else if (val[r][c] != v) {
                                    ok = false;
                                }
                            };

                            while (q.size() && ok) {
                                int r = q.front().first;
                                int c = q.front().second;
                                int v = val[r][c];
                                q.pop();

                                flg[r][c] = true;

                                if (s[c] != '?') {
                                    push(1 - r, c, (s[c] - '0') ^ v);
                                }
                                if (r == 0) {
                                    if (c == m && v != 1) {
                                        ok = false;
                                    }
                                    if (m <= c) {
                                        push(r, n - (c - m) - 1, v);
                                    } else if (v) {
                                        ok = false;
                                        break;
                                    }
                                } else {
                                    push(r, n - c - 1, v);
                                }
                            }
                            if (ok) {
                                addmod(res, delta);
                            }
                        }
                    }
                }
            }
            addmod(answer, res);
        }
        cout << answer << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}