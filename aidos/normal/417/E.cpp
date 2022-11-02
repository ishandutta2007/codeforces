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

#define MAXN (int) (1e8)
using namespace std;
vector < int > get(int x){
	vector < int > v;
	if(x == 1) v.pb(1);
	else if(x == 2){
		v.pb(3);
		v.pb(4);
	}
	else {
		for(int i = 0; i+2 <x ; i++) 
			v.pb(1);
		if(x % 2 == 0) {
			v.pb(1);
			v.pb(x/2-1);
		}
		else {
			v.pb(2);
			v.pb(x/2+1);
		}
	}
	return v;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector < int > v = get(n), g = get(m);
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++)
    		cout << v[i] * g[j] << " ";
    	cout << endl;
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}