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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

pii a[maxn];
int n;
ll r, avg;


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> r >> avg;
    ll aa = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].s >> a[i].f;
        aa += a[i].s;
    }
    sort(a, a + n);
    ll need = 0;
    for(int i = 0; i < n; i++){
        ll x = min(r - a[i].s, max(avg * 1ll * n - aa, 0ll));
        aa += x;
        need += x * 1ll * a[i].f;
    }
    cout << need << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}