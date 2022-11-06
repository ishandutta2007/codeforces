#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
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
const ll inf = 1LL<<60;
const ll md = 1e9+7;
const ld eps = 1e-14;
const ld pi = acos(-1);

ll f(ll a, int bb, vl &sum, vl &as, vl &hull){
	ll b = hull[bb];
	return sum[a] - sum[b] + (b-a)*as[a];
}

int main(){
	int n;
	scanf("%d",&n);
	vl as(n);
	rep(i,0,n) scanf("%lld",&as[i]);
	vl sm(n+1);
	sm[0] = 0;
	rep(i,0,n) sm[i+1] = sm[i] + as[i];
	vl hull;
	rep(i,0,n+1){
		while(hull.size() >= 2){
			ll sz = hull.size();
			ll k = hull[sz-2], j = hull[sz-1];
			if((sm[j]-sm[k])*(i-j) >= (sm[i]-sm[j])*(j-k)){
				hull.pop_back();
			} else {
				break;
			}
		}
		hull.pb(i);
	}
	ll ans = 0;
	ll def = 0;
	rep(i,0,n) def += (i+1)*as[i];
//for(int h : hull) cout << h << ' ';
//cout << endl;
//cout << def << endl;
	rep(i,0,n){
		int a = -1, b = hull.size()-1;
		while(a+1 < b){
			int m = (a+b)/2;
			if(f(i,m,sm,as,hull) < f(i,m+1,sm,as,hull))
				a = m;
			else
				b = m;
		}
		ans = max(ans, f(i,a+1,sm,as,hull));
	}
	printf("%lld\n",ans+def);
}