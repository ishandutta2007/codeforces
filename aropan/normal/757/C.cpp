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
#include <iomanip>

using namespace std;

#define fst first
#define snd second

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MAXX = 1e+6 + 7;
const int MOD = 1e+9 + 7;

ll f[MAXX];
int p[MAXX];
int a[MAXX];
vector < vector < pair <int, int > > > v;

bool opr_sort(const int &i, const int &j) {
    return v[i] < v[j];
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
#endif

    f[0] = 1;
    for (int i = 1; i < MAXX; ++i) {
        f[i] = f[i - 1] * (ll)i % MOD;
    }

    int n, m;
    while (cin >> n >> m && n && m) {
        v.clear();
        memset(p, 0, sizeof(p));
        for (int j = 0; j < n; ++j) {
            map <int, int> c;
            int k;
            cin >> k;
            for (int i = 0; i < k; ++i) {
                int x;
                cin >> x;
                c[x] += 1;
            }
            map <int, int> g;
            int ind = 0;
            for (auto& it : c) {
                int x = it.first;
                int y = it.second;
                if (g.find(y) == g.end()) {
                    g[y] = ++ind;
                }
                int t = g[y];
                if (p[x] == 0) {
                    p[x] = v.size() + 1;
                    v.push_back(vector < pair <int, int> >());
                }
                v[p[x] - 1].emplace_back(j, t);
            }
        }
        int k = v.size();
        ll ans = f[m - k];
        for (size_t i = 0; i < k; ++i) {
            a[i] = i;
        }
        sort(a, a + k, opr_sort);
        // for (int i = 0; i < k; ++i) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        for (int i = 0, j = 0; i < k; i = j) {
            while (j < k && v[a[i]] == v[a[j]]) {
                ++j;
            }
            ans = ans * f[j - i] % MOD;
        }
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}