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



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    set < pll > S;
    int n, k;
    scanf("%d %d\n", &n, &k);
    for(int i = 0; i < n; i++){
    	ll x, y;
    	scanf("%I64d %I64d", &x, &y);
    	if(S.size() == k){
    		pll xx = *S.begin();
    		S.erase(S.begin());
    		x = max(xx.f, x) + y;
    		printf("%I64d\n", x);
    		S.insert(mp(x, xx.s));
    	}
    	else {
    		x += y;
    		printf("%I64d\n", x);
    		S.insert(mp(x, i));
    	}
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}