#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;

int main(){
	cin.sync_with_stdio(false);
	ll n,a,b,t;
	cin >> n >> a >> b >> t;
	string str;
	cin >> str;
	vi cw(n+1);
	rep(i,0,n) cw[i+1] = cw[i] + (str[i] == 'w');
	ll ans = 0;
	rep(s,1,n+1){
		if(cw[s]*b + a*(s-1)+s > t) break;
		ans = max(ans, ll(s));
		int lo = s-1, hi = n+1;
		while(lo+1 < hi){
			int mi = (lo+hi)/2;
			ll t1 = cw[s]*b + a*(s-1) + a*(s + n-mi - 1) + (cw[n] - cw[mi])*b;
			ll t2 = cw[s]*b + a*(n-mi) + a*(s + n-mi - 1) + (cw[n] - cw[mi])*b;
			if(min(t1, t2)+s+n-mi <= t)
				hi = mi;
			else
				lo = mi;
		}
		ans = max(ans, s + n-hi);
	}
	if(b*cw[1]+1 <= t){
		int s = 0;
		while(s <= n-2 && b*(cw[n] - cw[n-s-1] + cw[1]) + a*(s+1)+s+2 <= t) ++s;
		if(s+1 > ans) ans = s+1;
	}
	cout << ans << endl;
}