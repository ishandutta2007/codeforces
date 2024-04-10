#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int a, b;
    cin >> a >> b;
    if( a < b){
        cout << -1 << endl;
        return 0;
    }

    if( b == a){
        cout << a << endl;
        return 0;
    }
    double c1 = a + b;
    int t = (int)(c1/b);
    if( t % 2 == 1) t--;

    double ans = 1e12;
    if( t > 0) ans = c1/t;
    double c2 = a - b;
    t = (int) (c2/b);
    if( t % 2 == 1) t--;
    if( t > 0) ans = min(ans, c2/t);
    printf("%.12lf", ans);










    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}