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

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MAXN = 7e+4 + 42;
const int MAXT = MAXN * 50;

int tree[MAXT][10];
int cnt[MAXT], upd[MAXT];
int t, upd_t;

int move(int x, int c) {
    if (tree[x][c] == 0) {
        tree[x][c] = ++t;
    }
    return tree[x][c];
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n) {
        memset(tree, 0, sizeof(tree));
        memset(cnt, 0, sizeof(cnt));
        t = 0;
        string s[n];
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            for (auto& c : s[i]) {
                c -= '0';
            }
        }
        for (int i = 0; i < n; ++i) {
            ++upd_t;
            int l = s[i].size();
            for (int j = 0; j < l; ++j) {
                int x = 0;
                for (int k = j; k < l; ++k) {
                    x = move(x, s[i][k]);
                    if (upd_t != upd[x]) {
                        ++cnt[x];
                        upd[x] = upd_t;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int l = s[i].size();
            int best = l;
            int pos = 0;
            for (int j = 0; j < l; ++j) {
                int x = 0;
                for (int k = j; k < l; ++k) {
                    x = move(x, s[i][k]);
                    if (cnt[x] == 1 && chmin(best, k - j + 1)) {
                        pos = j;
                    }
                }
            }
            for (auto& c : s[i]) {
                c += '0';
            }
            cout << s[i].substr(pos, best) << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}