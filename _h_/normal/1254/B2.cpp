#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll inf = 2e18;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi a(n);
	trav(x, a) cin >> x;

	ll tot = 0;
	trav(x, a) tot += x;
	if(tot == 1){
		cout << -1 << endl;
		return 0;
	}

	vector<ll> factors;
	for(ll d = 1; d*d <= tot; ++d) if(tot % d == 0){
		factors.push_back(d);
		factors.push_back(tot / d);
	}
	sort(all(factors));
	vector<ll> primes;
	trav(d, factors) if(d > 1){
		trav(p, primes) if(d % p == 0) goto done;
		primes.push_back(d);
		done: ;
	}
	ll ans = inf;

	trav(p, primes){
		ll cur = 0;
		ll carry = 0;
		rep(i,0,n){
			ll r = a[i] + carry;
			r %= p;
			if(r < 0) r += p;
			if(r == 0){
				carry = 0;
			} else if(r < p-r){
				cur += r;
				carry = r;	
			} else {
				cur += p-r;
				carry = r;
			}
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
}