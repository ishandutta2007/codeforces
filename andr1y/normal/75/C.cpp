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
int main(){
	FAST;
	ll a, b;
	cin >> a >> b;
	ll g = __gcd(a, b);
	set<ll> divs;
	divs.insert(1);
	ll on = g;
	for(ll i = 2;i*i<=g;i++){
		while(on%i==0){
			set<ll> divscp = divs;
			for(auto ii : divscp) divs.insert(ii*i);
			on/=i;
		}
	}
	if(on != 1){
		set<ll> divscp = divs;
			for(auto ii : divscp) divs.insert(on*ii);
	}
	vector<ll> d2;
	for(auto i : divs) d2.pb(i);
	ll q;
	cin >> q;
	while(q--){
		ll l, r;
		cin >> l >> r;
		bool f = 0;
		for(ll i = d2.size()-1;i>=0;i--){
			if(d2[i] >= l && d2[i] <= r){
				cout << d2[i] << endl;
				f = 1;
				break;
			}
		}
		if(!f) cout << -1 << endl;
	}
}