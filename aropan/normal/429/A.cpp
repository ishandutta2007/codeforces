#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 100005;

vector <int> e[MAXN];
int f[MAXN];
vector <int> ans;
int n;

void dfs(int x, int p, int v, int _v)
{
    if (f[x] != v) {
        ans.push_back(x);
        v ^= 1;
    }
    foreach (it, e[x]) {
        int y = *it;
        if (y == p) {
            continue;
        }
        dfs(y, x, _v, v);
    }
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int iter = 0; iter < 2; ++iter) {
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            f[i] ^= x;
        }
    }
    dfs(1, 0, 0, 0);
    cout << ans.size() << endl;
    foreach (it, ans) {
        cout << *it << "\n";
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}