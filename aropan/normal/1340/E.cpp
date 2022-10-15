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

vector<vector<int>> e;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(428);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<vector<int>> dists(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        auto& d = dists[i];
        queue<int> q;
        q.push(i);
        d[i] = 0;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int y : e[x]) {
                if (d[y] == -1) {
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
        }
    }
    set<int> st;
    vector<int> v(3);
    for (int i = 0; i < 3; ++i) {
        do {
            v[i] = rand() % n;
        } while (st.count(v[i]));
        st.insert(v[i]);
    }
    int target = -1;
    for (;;) {
        bool ok = false;
        for (int i = 0; i < 3; ++i) {
            if (i) {
                cout << " ";
            }
            cout << v[i] + 1;
            if (target == v[i]) {
                ok = true;
            }
        }
        cout << endl;
        cout.flush();

        if (ok) {
            break;
        }

        cin >> target;
        --target;
        for (int i = 0; i < 3; ++i) {
            if (target == v[i]) {
                ok = true;
            }
        }
        if (ok) {
            break;
        }

        vector<int> p = {0, 1, 2};
        sort(all(p), [&](const int a, const int b) { return dists[target][a] < dists[target][b]; });

        set<int> st;
        for (auto& i : p) {
            int x = v[i];
            int opt = (int)1e+9;
            int t = x;
            random_shuffle(all(e[x]));
            for (auto& y : e[x]) {
                if (st.count(y)) {
                    continue;
                }
                if (chmin(opt, dists[target][y])) {
                    t = y;
                }
            }
            v[i] = t;
            st.insert(t);
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}