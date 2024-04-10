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
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
ll a[N], p[N];
ll n, s;
ll bs(ll wh, ll ip){
	ll l = 0, r = n-1;
	while(r-l>1){
		ll m = (l+r)>>1;
		if(p[m] <= wh+(m >= ip ? a[ip] : 0)) l =m;
		else r = m;
	}
	for(ll m = r;m>=l;m--) if(p[m] <= wh+(m >= ip ? a[ip] : 0)) return m;
	return -1;
}
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		cin>> n >> s;
		for(ll i= 0;i<n;i++) {cin >> a[i];p[i] = a[i] + (i > 0 ? p[i-1] : 0);}
		if(p[n-1] <= s){
			cout << 0 << endl;
			continue;
		}
		ll res = -1, rv = 0;
		for(ll i =0;i<n;i++){
			ll vx = bs(s, i);
			if(vx > res) res = vx, rv = i;
		}
		cout << rv+1 << endl;
	}
}