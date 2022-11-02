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

ll a[1000010];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, p;
    scanf("%d", &n);
    ll x = 0, y= 0;
    
    for(int i = 0; i < n; i++){
    	scanf("%d", &p);
    	y ^= p;
    }
    a[0] = 0;
    for(ll i = 1; i <= n; i++){
    	int z = n % i;
    	a[i] = (a[i-1] ^ i);
    	y ^= a[z];
    	if( ((n - z ) / i ) % 2){
    		y ^= a[i-1];
    	}
    }
  /*  for(int i = 1; i <=n; i++){
    	for(int j = 1; j <= n; j++){
    		x ^= (i % j);
    		cout <<  i% j << " " ;
    	}
    	cout << endl;
    }   */

    cout << y << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}