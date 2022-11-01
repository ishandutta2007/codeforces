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

int n;

ld getms(ld t, const vector <ld> a) {
    ld minpref, maxpref;
    ld minv, maxv;

    minpref = maxpref = 0;

    minv = maxv = a[0] - t;

    ld curpref = 0;
    for (int i = 0; i < a.size(); ++i) {
        curpref += a[i] - t;

        minv = min(minv, curpref - maxpref);
        maxv = max(maxv, curpref - minpref);

        maxpref = max(maxpref, curpref);
        minpref = min(minpref, curpref);
    }
    return max(fabs(minv), fabs(maxv));
}

void solve() {
    cin >> n;
    vector <ld> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ld l, r, x1, x2;
    
    ld phi = (1 + sqrt(5)) / 2;
    ld resphi = 2 - phi;
    
    ld f1, f2;
    
    ld ans = getms(0, a);

    for (int i = 0; i < 2; ++i) {
        l = 0;
        r = 20000;
        x1 = l + resphi * (r - l);
        x2 = r - resphi * (r - l);
        f1 = getms(x1, a);
        f2 = getms(x2, a);

        for (int it = 0; it < 200; ++it) {
            if (f1 < f2) {
                r = x2;
                x2 = x1;
                f2 = f1;
                x1 = l + resphi * (r - l);
                f1 = getms(x1, a);
            }
            else {
                l = x1;
                x1 = x2;
                f1 = f2;
                x2 = r - resphi * (r - l);
                f2 = getms(x2, a);
            }
        }

        ans = min(ans, getms(l, a));

        for (int i = 0; i < n; ++i) {
            a[i] = -a[i];
        }
    }
    cout << ans << endl;
}