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

int n, k;
int a[111];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &k);
    for(int i = 0, x; i < n; i++){
    	scanf("%d", &x);
    	a[x]++;
    }
    for(int i = 9; i > 0; i--){
    	for(int j = 0; j < 10; j++){
    		int t = min(a[j * 10 + i] * (10 - i), k)/(10-i);
    		a[(j + 1) * 10] += t;
    		a[j * 10 + i] -= t;
    		k -= t * ( 10 - i );
    	}
    }

    int ans = 0;
    for(int i = 0; i < 100; i++){
    	if( (100 - i) * a[i] <= k){
    		a[100] += a[i];
    		k -=(100 - i) * a[i];
    		a[i] = 0;
    	}else {
    		int t = k/(100-i);
    		a[i] -= t;
    		a[100] += t;
    		t = k % (100-i);
    		a[i + t]++;
    		a[i]--;
    		break;
    	}
    }

    for(int i = 0; i <=100; i++){
    	ans += a[i] * (i/10);
    }
    cout << ans << endl;





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}