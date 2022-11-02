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

#define MAXN (int) (1e7)
using namespace std;

int n, t, c, a[211111];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif                 
    cin >> n >> t >> c;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    if( c== 0){
    	cout << 0;
    	return 0;
    }
    int ans = 0, k= 0, y;
    while(k < n){
    	y = k;
    	while( k < n && a[k] <=t){
    		k++;
    	}
    	int z = k - y;
    	if(z >= c){
    		ans += (z + 1-c);
    	}

    	k++;
    }
    cout << ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}