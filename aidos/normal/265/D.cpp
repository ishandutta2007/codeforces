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
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e5+10)
using namespace std;
int a[MAXN], x, n;
int d[MAXN];
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    int ans = 1;
    for(int i = 0; i < n; i++){
        cin >> x;
        int mx = 0;
        for(int j = 2; j * j <= x; j++){
            if( x % j) continue;
            mx = max(mx, d[j]);
            mx = max(mx, d[x/j]);
        }
        d[x] = mx + 1;

        for(int j = 2; j * j <= x; j++){
            if( x % j) continue;
            d[j] = d[x];
            d[x/j] = d[x];
        }
        ans = max(d[x], ans);
    }
    cout << ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}