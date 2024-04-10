#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll qmin(ll a, ll b){
	return (a < b) ? a : b;
}
ll qmax(ll a, ll b){
	return (a > b) ? a : b; 
}

int T;
ll x[5], y[5];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		rep(i, 4) cin >> x[i] >> y[i];
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1; i < 4; i++){
			ll xl1, xr1, xl2, xr2;
			xl1 = xl2 = 0x3f3f3f3f3f3f3f3f;
			xr1 = xr2 = 0xc0c0c0c0c0c0c0c0;
			xl1 = qmin(x[0], x[i]);
			xr1 = qmax(x[0], x[i]);
			rep(k, 4) if(k && k != i) xl2 = qmin(xl2, x[k]), xr2 = qmax(xr2, x[k]);
			ll xll, xlr, xrl, xrr;
			xll = qmin(xl1, xl2), xlr = qmax(xl1, xl2);
			xrl = qmin(xr1, xr2), xrr = qmax(xr1, xr2);
			ll xl = qmax(0, xlr - xrl);
			ll xr = xrr - xll;
			for(int j = 1; j < 4; j++){
				if(i == j) continue;
//				cout << i << " " <<j << endl;
				ll yl1, yr1, yl2, yr2;
				yl1 = yl2 = 0x3f3f3f3f3f3f3f3f;
				yr1 = yr2 = 0xc0c0c0c0c0c0c0c0;
				yl1 = qmin(y[0], y[j]);
				yr1 = qmax(y[0], y[j]);
				rep(k, 4) if(k && k != j) yl2 = qmin(yl2, y[k]), yr2 = qmax(yr2, y[k]);
				ll yll, ylr, yrl, yrr;
				yll = qmin(yl1, yl2), ylr = qmax(yl1, yl2);
				yrl = qmin(yr1, yr2), yrr = qmax(yr1, yr2);
				ll yl = qmax(0, ylr - yrl);
				ll yr = yrr - yll;
				ll res = xr1 - xl1 + xr2 - xl2 + yr1 - yl1 + yr2 - yl2;
//				cout << xl1 << " " << xr1 << "  " << xl2 << " " << xr2 << "; " << yl1 << " " << yr1 << "  " << yl2 << " " << yr2 << endl;
				if(qmax(xl, yl) <= qmin(xr, yr)){
					ans = qmin(ans, res);
				} else {
					ans = qmin(ans, res + 2 * (qmax(xl, yl) - qmin(xr, yr)));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}