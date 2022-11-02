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

int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int a[111];
    int n, m;
    cin >> n >> m;
    int c =0;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    while(1){
    	int t = 0;
    	for(int i = 0; i<n; i++){
    		if( t + a[i] <= m){
    			t += a[i];
    			a[i] = 0;
    		}
    		else break;

    	}
    	c++;
    	int x = 0;
    	for(int i = 0; i<n; i++){
    		x += a[i];
    	}
    	if( x == 0 )  break;
    }
    cout << c << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}