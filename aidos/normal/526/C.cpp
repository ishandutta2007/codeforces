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


int n = (int)1e7;
ll w1, h1, w2, h2, c;
ll ans = 0;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> c >> h1 >> h2 >> w1 >> w2;
	ll C = c;
	ll cur = 0;
    for(int i = 0; i<= n; i++, C -= w1, cur += h1){
    	if(C < 0) break;
    	else ans = max(ans, (C/w2) * 1ll * h2 + cur);
    }
    C = c;
	cur = 0;
    for(int i = 0; i<= n; i++, C -= w2, cur += h2){
    	if(C < 0) break;
    	else ans = max(ans, (C/w1) * 1ll * h1 + cur);
    }
    cout << ans << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}