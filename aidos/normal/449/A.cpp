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
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
vector < ll > ans;
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ll n, m, k;
    cin >> n >> m >> k;
    if( n +m-2 < k){
        cout << -1;
        return 0;
    }
    ll kk = min(k, n-1);
    ll nn = n/(kk+1);
    ll mm = m/(k - kk + 1);
    ll get = nn * 1ll * mm;
    kk = min(k, m-1);
    mm = m/(kk+1);
    nn = n/(k - kk + 1);
    get= max(get, nn  *1ll * mm);
    k+=2;
    for(int i = 2; i * 1ll * i <= n; i++){
        ll x = n/(i + 1);
        ll z = n/i;
        x--;
        if( k > z){
            ll y = max(1ll, k - z);
            mm = m/y;
            nn = i;
            get = max(get, nn * 1ll * mm);
        }
        x = n/(z + 1);
        x--;
        if( k > i){
            ll y = max(1ll, k - i);
            mm = m/y;
            nn = z;
            get = max(get, mm * 1ll * nn);
        }
    }
    cout << get << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}