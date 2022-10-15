#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MOD = 1000000007;

vector < vector <int> > e;
vector < ll > z, o;
vector < int > color;

void dfs(int x, int p)
{
    z[x] = color[x] == 0;
    o[x] = color[x] == 1;
    for (size_t i = 0; i < e[x].size(); ++i) {
        int y = e[x][i];
        if (y == p) {
            continue;
        }
        dfs(y, x);
        ll _z = z[x], _o = o[x];
        z[x] = _z * (z[y] + o[y]) % MOD;
        o[x] = (_o * (z[y] + o[y]) + _z * o[y]) % MOD;
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    cin >> n;
    e.resize(n);
    z.resize(n);
    o.resize(n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        e[x].push_back(i);
        e[i].push_back(x);
    }
    color.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }
    dfs(0, -1);
    cout << o[0] << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}