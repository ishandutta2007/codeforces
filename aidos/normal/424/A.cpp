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
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector < char > v;
    int l = 0, r= 0;
    for(int i = 0; i < n; i++){
    	char c;
    	cin >> c;
    	v.pb(c);
    	if(c == 'X' ){
    		l++;
    	}
    	else r++;
    }
    if(l > r) {
    	cout << ( l -r)/2 << endl;
    	for(int i = 0; i < n; i++){
    		if(l == r) cout << v[i];
    		else if( l> r && v[i] == 'X'){
    			cout << 'x';
    			l--;
    			r++;
    		}
    		else cout << v[i];
    	}
    }
    else {
    	cout << ( r - l)/2 << endl;
    	for(int i = 0; i < n; i++){
    		if(l == r) cout << v[i];
    		else if( r > l && v[i] == 'x'){
    			cout << 'X';
    			r--;
    			l++;
    		}
    		else cout << v[i];
    	}
    
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}