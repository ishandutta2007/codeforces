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
    //freopen("output.txt", "w", stdout);
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

struct Point {
    int x, y;
    Point(){}
    Point(int x, int y):x(x),y(y){}
    ld dist() {
        return sqrt(ld(x * x + y* y));
    }
    Point operator - (Point& oth) {
        return Point(x - oth.x, y - oth.y);
    }
    void scan() {
        cin >> x >> y;

    }
};

void solve() {

    vector <Point> a(2);

    for (int i = 0; i < 2; ++i) {
        a[i].scan();
    }
    Point t;
    t.scan();
    int n;
    cin >> n;

    vector <Point> b(n);

    ld result = 0;

    for (int i =0 ; i < n; ++i) {
        b[i].scan();
        result += (b[i] - t).dist() * 2.0;
    }

    vector <int> best[2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            best[i].push_back(j);
            if (best[i].size() > 2) {
                int pos_maxi = 0;
                ld cur_maxi = (b[best[i][0]] - a[i]).dist() - (b[best[i][0]] - t).dist();
                for (int j = 1; j < best[i].size(); ++j) {
                    if ((b[best[i][j]] - a[i]).dist() - (b[best[i][j]] - t).dist() > cur_maxi) {
                        cur_maxi = (b[best[i][j]] - a[i]).dist() - (b[best[i][j]] - t).dist();
                        pos_maxi = j;
                    }
                }
                swap(best[i][pos_maxi], best[i].back());
                best[i].pop_back();
            }
        }
    }

    set <int> all_ind;
    for (int i = 0; i < 2; ++i) {
        for (int j: best[i]) {
            all_ind.insert(j);
        }
    }

    vector <int> tmp;
    for (int x: all_ind) {
        tmp.push_back(x);
    }
    ld best_res = -1;

    for (int i = 0; i < 2;  ++i) {
        for (int u = 0; u < tmp.size(); ++u) {
            ld dec = (b[tmp[u]] - a[i]).dist() - (b[tmp[u]] - t).dist();
            if (best_res == -1)
                best_res = result + dec;
            else {
                best_res = min(best_res, result + dec);}
        }
    }

    for (int u = 0; u < tmp.size(); ++u) {
        ld dec[2] = {0, 0};

        for (int v = 0; v < tmp.size(); ++v) {
            if (v == u) {
                continue;
            }

            dec[0] = (b[tmp[u]] - a[0]).dist() - (b[tmp[u]] - t).dist();
            dec[1] = (b[tmp[v]] - a[1]).dist() - (b[tmp[v]] - t).dist();
            best_res = min(best_res, result + dec[0] + dec[1]);
        }
    }
    cout << best_res << endl;
}