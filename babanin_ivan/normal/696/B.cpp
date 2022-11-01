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


vector <vector <int>>g;

vector <int> ans;
vector <int> sum;
vector <int> depth;

void dfs(int v, int par=-1) {
    sum[v] = 1;
    if (par == -1) {
        depth[v] = 1;
    }
    else {
        depth[v] = depth[par] + 1;
    }
    for (int u: g[v]) {
        if (par == u) {
            continue;
        }
        dfs(u, v);
        sum[v] += sum[u];
    }

}
void dfs2(int v, int curval, int par=-1) {
    ans[v] = curval;
    for (int u: g[v]) {
        if (par == u) {
            continue;
        }
        dfs2(u, curval + sum[v] - 1 - sum[u], v);

    }

}


void solve() {
    int n;
    cin >> n;
    g.resize(n);
    sum.resize(n);
    ans.resize(n);
    depth.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    dfs(0);
    dfs2(0, 0);
    for (int i =0 ;i < n; ++i) {
        cout << ans[i] / 2.0 + depth[i] * 1.0 << " ";
    }
}