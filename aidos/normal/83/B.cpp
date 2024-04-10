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
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
ll k, n, sum = 0;
int a[111000];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif  
    scanf("%I64d%I64d", &n, &k);
    set < pii > s;
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    	sum+=a[i];
    	s.insert(mp(a[i], i));
    }
    if(sum < k) cout << -1;
    else if(sum>k){
    	ll x = 0, gg = 0;
    	while(1){
    		ll z = s.begin() -> ff - x, v = s.size();
    		if(z * 1ll * v + gg <= k){
    			gg += z * 1ll * v;
    			x+=z;
    			ll t = s.begin()->ff;
    			while(s.begin()->ff == t){
    				s.erase(s.begin());
    			}
    		}
    		else {
    			ll t = (k - gg)/v;
    			gg+=t*1ll*v;
    			x += t;
    			break;
    		}
    	}
    	k -= gg;
    	vector < pii > v, u;
    	for(set < pii > :: iterator it = s.begin(); it != s.end(); it++){
    		v.pb(mp(it->sc, it->ff - x));
    	}
    	sort(v.begin(), v.end());
    	reverse(v.begin(), v.end());
    	while(k > 0){
    		k--;
    		pii f = v[v.size()-1];
    		if(f.sc > 1) u.pb(f);
    		v.pop_back();
    	}
    	for(int i = v.size()-1; i>=0; i--)
    		cout << v[i].ff+1 << " ";
		for(int i = 0; i<u.size(); i++)
			cout << u[i].ff+1 << " ";
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}