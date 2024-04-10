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

pii a[100100];
int n;
int d;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    ll sum = 0;
    int r = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> a[i].f >> a[i].s;
    sort(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        while( r < n && a[r].f < a[i].f + d) {
            sum += a[r].s;
            r++;
        }
        ans = max(sum, ans);
        sum -= a[i].s;
    }
    cout << ans << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}