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
#include <cassert>

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

int sum, limit;
vector < pii > v;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> sum >> limit;
    ll sum2 = 0;

    for(int i = 1; i <= limit && sum2 < sum; i++){
    	int x = i;
    	while( x % 2 == 0) {
    		x/=2;
    	}
    	sum2  += i/x;
    	v.pb(mp(i/x, i));
    }
    if(sum2 < sum){
    	cout << -1 << endl;
    	return 0;
    }
    #ifdef LOCAL
    for(int i = 0; i < v.size(); i++){
    	cout << v[i].f << " " << v[i].s << endl;
	}
	#endif
	sort(v.begin(), v.end());
	vector < int > ans;

	for(int i = v.size()-1; i >= 0;  i--){
		if(sum >= v[i].f){
			sum -= v[i].f;
			ans.pb(v[i].s);
		}
	}
		cout << ans.size() << endl;
		forit(it, ans) cout << *it << " ";
	cout << endl;
    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}