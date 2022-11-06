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
#define x first
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
typedef long double ld;

bool smile(const pll &le, const pll &mi, const pll &ri){
	return ld(ri.y-mi.y)*(mi.x-le.x) > ld(mi.y-le.y)*(ri.x-mi.x);
}

int main(){
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vl a(n);
	rep(i,0,n) cin >> a[i];
	vl is(n+1), ss(n+1);
	rep(i,0,n){
		is[i+1] = is[i] + (i+1)*a[i];
		ss[i+1] = ss[i] + a[i];
	}
	ll ans = 0;
	vector<pll> hull(n+10);
	int ix = 0;
	rep(s,1,n+1){
		pll ny(s-1, ss[s-1]*(s-1) - is[s-1]);
		while(ix >= 2 && smile(hull[ix-2],hull[ix-1],ny)){
			--ix;
		}
		hull[ix++] = ny;
		auto f = [&](const pll &pa){
			return is[s] - ss[s]*pa.x + pa.y;
		};
		int lo = 0, hi = ix;
		while(lo+1 < hi){
			int mi = (lo+hi)/2;
			if(f(hull[mi]) > f(hull[mi-1]))
				lo = mi;
			else
				hi = mi;
		}
		ans = max(ans, f(hull[lo]));
	}
	cout << ans << endl;
}