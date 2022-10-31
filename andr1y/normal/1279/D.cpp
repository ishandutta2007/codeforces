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
#define M 998244353
#define N 1001001
#define INF 101111111111111
using namespace std;
vector<ll> kek[N];
ll bpm(ll a, ll b){
	if(b == 0) return 1;
	if(b == 1) return a%M;
	ll x = bpm((a*a)%M, b/2);
	if(b&1) x = (x*a)%M;
	return x;
}
int main(){
	FAST;
	ll n;
	cin >> n;
	for(ll b, a, i=0;i<n;i++){
		cin >> b;
		for(ll j = 0;j<b;j++) {cin >> a;kek[a].pb(b);}
	}
	ll res = 0;
	for (ll i =0;i<=1000*1000;i++) {
		if (kek[i].size() != 0) {
			ll kf = 1;
			for (auto ii : kek[i]) kf = (kf*ii) %M;
			for (auto ii : kek[i]) {
				ll cur = (bpm(ii, M-2)*kek[i].size()) %M;
				res = (res+cur)%M;
			}
		}
	}
	res = (res*bpm((n*n)%M, M-2))%M;
	cout << res << endl;
}