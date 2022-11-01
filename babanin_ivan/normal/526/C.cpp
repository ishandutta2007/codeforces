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
    while (t--) {
        //++timer;
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

#define int li

int gcd (int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
 
bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    return true;
}

void solve() {
    int c;
    int h[2];
    int w[2];
    cin >> c;
    cin >> h[0] >> h[1];
    cin >> w[0] >> w[1];

    if (w[0] > w[1]) {
        swap(h[0], h[1]);
        swap(w[0], w[1]);
    }

    li ans = 0;

    if (w[1] >= 10000) {
        for (int x = 0; ; ++x) {
            if (x * w[1] > c) {
                break;
            }
            int y = (c - x * w[1]) / w[0];
            if (x * h[1] + y * h[0] > ans){
                ans = x * h[1] + y * h[0];
            }
        }
        cout << ans << endl;
        return;
    }

    for (int d = 0; d <= 10100; ++d) {
        if (c <= d) {
            break;
        }
        li x[2], g;
        bool f = find_any_solution(w[0], w[1], c - d, x[0], x[1], g);
        if (f) {
            int tmp[2];
            tmp[0] = w[1] / g;
            tmp[1] = w[0] / g;
            for (int i = 0; i < 2; ++i) {
                if (x[i] < 0) {
                    li mn = (-x[i]) / tmp[i];
                    x[i] = x[i] + mn * tmp[i];
                    x[!i] = x[!i] - mn * tmp[!i];
                    if (x[i] < 0) {
                        x[i] += tmp[i];
                        x[!i] -= tmp[!i];
                    }
                }
            }
            if (x[0] < 0 || x[1] < 0) {
                continue;
            }
            for (int i = 0; i < 2; ++i) {
                li mn = x[i] / tmp[i];
                ans = max(ans, h[0] * (x[0] + mn * tmp[0]) + h[1] * (x[1] + mn * tmp[1]) - 2 * h[i] * mn * tmp[i]);
            }
        }
    }
    cout << ans << endl;
}