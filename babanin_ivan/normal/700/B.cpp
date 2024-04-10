#pragma comment (linker, "/STACK:128000000")
#include <iostream>
#include <cstdio>
#include <fstream>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <ctime>
#include <sstream>
#include <stack>
#include <cassert>
#include <list>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;

    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

#define int li

vector <int> u;
vector <vector <int> > g;
int ans = 0;
vector <int> sum;
vector <int> h;

void dfs(int v, int p=-1) {
    if (p != -1) {
        h[v] = h[p] + 1;
    }
    if (u[v]) {
        ans += h[v];
    }

    sum[v] = u[v];
    for (int u: g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
        sum[v] += sum[u];
    }
}

void dfs2(int v, int dropped, int p=-1) {
    dropped += u[v];
    int maxv = -1;
    int all_sum = 0;
    int v_withmaxv = -1;
    for (int u: g[v]) {
        if (u == p) {
            continue;
        }
        if (sum[u] > maxv) {
            maxv = sum[u];
            v_withmaxv = u;
        }

        all_sum += sum[u];
    }

    if (maxv == -1) {
        return;
    }

    if (maxv - dropped <= (all_sum - dropped) / 2) {
        return;
    }
    else {
        int others = all_sum - maxv;
        ans -= maxv - dropped - others;
        dfs2(v_withmaxv, dropped + others, v);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    u.resize(n);
    sum.resize(n);
    g.resize(n);
    h.resize(n);

    for (int i = 0; i < 2 * k; ++i) {
        int v;
        cin >> v;
        --v;
        u[v] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);
    dfs2(0,0);
    cout << ans;
}