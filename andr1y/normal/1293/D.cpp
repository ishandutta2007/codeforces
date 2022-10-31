#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL
#define M 1000000007
#define N 200200
#define INF 101111111111111LL
#define y0 y123423
using namespace std;
using python = void;
 
ll x0, y0, ax, bx, ay, by, xs, ys, t;
ll bp(ll a, ll b){
	if(b == 0) return 1;
	if(b == 1) return a;
	ll x = bp(a*a, b/2);
	if(b&1) x*=a;
	return x;
}
ll sumgeom(ll af, ll stp, ll n){
	if(stp == 1) return n*af;
	else return af*(bp(stp, n)-1)/(stp-1);
}
ll get_xp(ll i){
	return bp(ax, i)*x0 + sumgeom(1, ax, i)*bx;
}
ll get_yp(ll i){
	return bp(ay, i)*y0 + sumgeom(1, ay, i)*by;
}
ll maxfrom(ll dt, ll vs, ll mxv){
	ll px = get_xp(dt), py = get_yp(dt);
	if(vs > t) return 0;
	// ll l = 0, r = dt;
	// while(r-l>1){
	// 	ll m = (l+r)>>1;
	// 	ll ppx = get_xp(m), ppy = get_yp(m);
	// 	ll tvs = abs(px-ppx)+abs(py-ppy);
	// 	if(vs + tvs <= t) r = m;
	// 	else l = m;
	// }
	// ll xr = dt;
	// for(ll m = l;m<=r;m++){
	// 	ll ppx = get_xp(m), ppy = get_yp(m);
	// 	ll tvs = abs(px-ppx)+abs(py-ppy);
	// 	if(vs + tvs <= t) {
	// 		xr = m;
	// 		break;
	// 	}
	// }
	// ll mxr1 = 1+dt-xr;
	// l = dt, r = mxv;
	// while(r-l>1){
	// 	ll m = (l+r)>>1;
	// 	ll ppx = get_xp(m), ppy = get_yp(m);
	// 	ll tvs = abs(px-ppx)+abs(py-ppy);
	// 	if(vs + tvs <= t) l = m;
	// 	else r = m;
	// }
	// xr = dt;
	// for(ll m = r;m>=l;m--){
	// 	ll ppx = get_xp(m), ppy = get_yp(m);
	// 	ll tvs = abs(px-ppx)+abs(py-ppy);
	// 	if(vs + tvs <= t) {
	// 		xr = m;
	// 		break;
	// 	}
	// }
	// return max(mxr1, 1+xr-dt);
	ll mxr= 0;
	for(ll i = 0;i<mxv;i++){
		mxr = max(mxr, ((ull)vs+abs(px-get_xp(i))+abs(py-get_yp(i)) <= (ull)t ? abs(i-dt)+1 : 0));
	}
	return mxr;
}
signed main(){
	FAST;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
	ull pax = x0;
	ll pcx= 1;
	while(pax <= 2e16) pax = pax*((ull)ax)+((ull)bx), pcx++;
	ull pay = y0;
	ll pcy= 1;
	while(pay <= 2e16) pay = pay*((ull)ay)+((ull)by), pcy++;
	ll l = 0, r = min(pcx, pcy);
	ll mxv = 0;
	for(ll m = 0;m<=r;m++){
		mxv=  max(mxv, maxfrom(m, abs(xs-get_xp(m))+abs(ys-get_yp(m)), r));
	}
	cout << mxv << endl;
}