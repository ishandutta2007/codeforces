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

using tupleiii = std::tuple<int, int, int>;

const int MAXN = 2e+5 + 42;
vector <int> e[MAXN];
vector<tupleiii> answer;
int used[MAXN];

bool dfs(int x, int p = -1) {
    used[x] = 1;
    vector <int> v;
    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        if (used[y]) {
            if (used[y] == 1) {
                v.push_back(y);
            }
            continue;
        }
        if (dfs(y, x)) {
            v.push_back(y);
        }
    }
    for (size_t i = 1; i < v.size(); i += 2) {
        answer.push_back(tupleiii(v[i - 1], x, v[i]));
    }
    if (p != -1 && (v.size() & 1)) {
        answer.push_back(tupleiii(*v.rbegin(), x, p));
    }
    used[x] = 2;
    return (v.size() & 1) == 0;
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
    while (cin >> n && n) {
        answer.clear();
        memset(used, 0, sizeof(used));

        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                dfs(i);
            }
        }
        cout << answer.size() << "\n";
        for (auto& t : answer) {
            cout << get<0>(t) + 1 << " " << get<1>(t) + 1 << " " << get<2>(t) + 1 << "\n";
        }

        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}