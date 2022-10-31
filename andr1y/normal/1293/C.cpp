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
#define N 100111
#define INF 101111111111111LL
using namespace std;
using python = void;
bool a[2][N];
ll fwt[N];
ll n;
void fwinc(ll p, ll d){
	for(;p<=n+1;p+=(p&-p)) fwt[p]+=d;
}
ll fwsum(ll r, ll s = 0){
	for(;r>0;r-=(r&-r)) s+=fwt[r];
	return s;
}
ll tw[N];
signed main(){
	FAST;
	ll q;
	cin >> n >> q;
	ll ban = 0;
	while(q--){
		ll r, c;
		cin >> r >> c;
		--r, c--;
		ll ir = (r+1)%2;
		if(!a[r][c]){
			if(r == 0){
				ll xc = 0;
				for(ll i = max<ll>(0, c-1);i<=min(n-1, c+1);i++) if(a[ir][i]) xc++;
				fwinc(c+1, xc);
			}else{
				for(ll i = max<ll>(0, c-1);i<=min(n-1, c+1);i++) if(a[ir][i]) fwinc(i+1, 1);
			}
		}else{
			if(r == 0){
				ll xc = 0;
				for(ll i = max<ll>(0, c-1);i<=min(n-1, c+1);i++) if(a[ir][i]) xc++;
				fwinc(c+1, -xc);
			}else{
				for(ll i = max<ll>(0, c-1);i<=min(n-1, c+1);i++) if(a[ir][i]) fwinc(i+1, -1);
			}
		}
		a[r][c] = !a[r][c];
		if(fwsum(n+1) == 0) cout << "Yes";
		else cout << "No";
		cout << '\n';
	}
}