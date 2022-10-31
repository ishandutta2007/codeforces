#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
int main(){
	// /FAST;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << 1 << " " << n-1 << " " << 1 << " ";
		for(ll i = 2;i<=n;i++) cout << i << " ";
		cout << endl;
		ll l = 2, r = n, xr;
		cin >> xr;
		while(r != l){
			ll m = (l+r)>>1;
			cout << "1 " << m-l+1 << " 1 ";
			for(ll i = l;i<=m;i++) cout << i << " ";
			cout << endl;
			ll xr2;
			cin >> xr2;
			if(xr2 == xr) r = m;
			else l = m+1;
		}
		// cout << "1 1 1 " << l << endl;
		// ll xt2;
		// cin >> xt2;
		// if(xt2 != xr) l = r; 
		ll xt;
		cout << "1 " << n-1 << " " << l << " ";
		for(ll i = 1;i<=n;i++) if(i!=l) cout << i << " ";
		cout << endl;
		cin >> xt;
		cout << "-1 " << xt << endl;
	}
}