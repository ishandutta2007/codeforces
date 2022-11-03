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
    int n, sum = 0;
    cin >> n >> sum;
    set < int > S;
    map < int, int > m;
    for(int i = 0; i < n; i++){
    	int x, y, k;
    	cin >> x >> y >> k;
    	int z = x * x + y * y;
    	m[z] += k;
    	S.insert(z);
    }
    for(set < int > :: iterator it = S.begin(); it!= S.end(); it++){
    	int z = *it;
    	sum += m[z];
    	if( sum >= 1000000){
    		double x = sqrt(1.0 * z);
    		printf("%.16lf\n", x);
    		return 0;
    	}
    }
    cout << -1;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}