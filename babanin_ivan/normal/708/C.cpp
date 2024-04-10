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

vector <vector <int> > g;
int n;
vector <int> dp1;
vector <int> sz;

void dfs1(int v, int p=-1) {
    sz[v] = 1;
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        dfs1(to, v);
        sz[v] += sz[to];
        dp1[v] = max(dp1[v], dp1[to]);
    }
    if (sz[v] <= n / 2) {
        dp1[v] = sz[v];
    }
}

vector <int> ans;

void dfs2(int v, int dpfromp=0, int p=-1) {
    if (p != -1) {
        g[v].erase(find(all(g[v]), p));
    }
    vector <int> prefmax(g[v].size() + 1);
    //vector <int> sufmax(g[v].size() + 1);

    for (int i = 0; i < g[v].size(); ++i) {
        prefmax[i + 1] = max(dp1[g[v][i]], prefmax[i]);
    }
//    for (int i = int(g[v].size()) - 1; i >= 1; --i) {
//        sufmax[i - 1] = max(sufmax[i], dp1[g[v][i]]);
//    }

    int already_good = 0;
    bool very_bad = false;
    for (int to: g[v]) {
        if (sz[to] > n / 2) {
            if (sz[to] - dp1[to] <= n / 2) {
                ++already_good;
            }
            else {
                very_bad = true;
            }
        }
    }
    int all_sum = sz[0] - sz[v];
    if (all_sum > n / 2) {
        if (all_sum - dpfromp <= n / 2) {
            ++already_good;
        }
        else {
            very_bad = true;
        }
    }
    if (!very_bad && already_good <= 1) {
        ans[v] = 1;
    }


    int sufmax = 0;
    for (int i = g[v].size() - 1; i >= 0; --i) {
        int to = g[v][i];

        int curmaxdp = dpfromp;
        if (sz[0] - sz[to] <= n / 2) {
            curmaxdp = sz[0] - sz[to];
        }
        curmaxdp = max(curmaxdp, max(prefmax[i], sufmax));

        dfs2(to, curmaxdp, v);

        sufmax = max(sufmax, dp1[to]);
    }
}

void solve() {
    cin >> n;
    g.resize(n);
    sz.resize(n);
    ans.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dp1.resize(n);
    dfs1(0);

    dfs2(0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}