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
map <int, int> lib;

void solve() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int v, u, w;
            cin >>v >> u >> w;
            while (v != u) {
                if (v > u) {
                    swap(v, u);
                }
                lib[u] += w;
                u /= 2;
            }
        }
        else {
            int v, u;
            cin >> v >> u;
            int ans = 0;
            while (v != u) {
                if (v > u) {
                    swap(v, u);
                }
                if (lib.count(u)) {
                    ans += lib[u];
                }
                u /= 2;
            }
            cout << ans << "\n";
        }
    }
}