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

vector <vector <pair <int, int> > > g;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    for (int i =0 ; i < m; ++i) {
        int x, y, l;
        cin >> x >> y >> l;
        --x;
        --y;
        g[x].push_back(mp(y, l));
        g[y].push_back(mp(x, l));
    }

    vector <int> used(n, -1);
    for (int i = 0; i < k; ++i) {
        int v;
        cin >> v;
        --v;
        used[v] = 0;
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            for (auto e: g[i]) {
                if (used[e.first] == -1) {
                    if (ans == -1 || ans > e.second) {
                        ans = e.second;
                    }
                }
            }
        }

    }
    cout << ans << endl;
}