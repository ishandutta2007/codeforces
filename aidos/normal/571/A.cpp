#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file "a"

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int mod = (int)1e9 + 7;



int main () {
    #ifdef LOCAL
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif
    int a, b, c, l;
    cin >> a >> b >> c >> l;

    ll ans = 0;
    for(int i = 0; i <= l; i++){
        ans += (l-i + 1) * 1ll * ( l - i + 2)/2;
    }
    for(int i = 0; i <= l; i++){
        int cc = a - b - c + i;
        if( cc < 0) continue;
        cc = min(cc, l - i);
        ans -= ( cc + 1) * 1ll * (cc + 2)/2;
    }
    for(int i = 0; i <= l; i++){
        int cc = b - a - c + i;
        if( cc < 0) continue;
        cc = min(cc, l - i);
        ans -= ( cc + 1) * 1ll * (cc + 2)/2;
    }
    for(int i = 0; i <= l; i++){
        int cc = c - b - a + i;
        if( cc < 0) continue;
        cc = min(cc, l - i);
        ans -= ( cc + 1) * 1ll * (cc + 2)/2;
    }
    cout << ans << endl;
    




    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}