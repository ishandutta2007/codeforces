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


vector <vector <int> > comps;

vector <int> used;
vector <vector <int> > g;

void dfs(int v, vector <int>& cur) {
    used[v] = true;
    cur.push_back(v);
    
    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to, cur);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g = vector <vector <int> >(n);
    used.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            comps.push_back(vector <int>());
            dfs(i, comps.back());
        }
    }
    
    int sum = 0;
    for (auto x: comps) {
        sum += int(x.size()) * int(x.size() - 1);
    }
    if (sum == m * 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}