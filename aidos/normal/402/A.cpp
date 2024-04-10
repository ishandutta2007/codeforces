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
int k, a, b, v;
bool check(int x){                        
	set < pii > s;
	for(int i=0; i <x; i++)
		s.insert(mp(1, i));
	ll ans = x * v, t = b;
	while(t > 0 && s.size() > 0){
		pii y = *s.begin();
		s.erase(s.begin());
		ans += v;
		y.ff++;
		if(y.ff < k){
			s.insert(y);
		}
		t--;
	}
	return ans >= a;
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> k >> a >> b >> v;
    for(int i=1; ; i++){
    	if(check(i)){
    		cout << i;
    		return 0;
    	}
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}