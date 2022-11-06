#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll md = 998244353LL;

ll mpow(ll a, ll e){
	a %= md;
	if(a < 0) a += md;
	ll res = 1;
	while(e){
		if(e&1) res = res * a % md;
		a = a * a % md;
		e /= 2;
	}
	return res;
}

ll inv(ll a){
	if(a%md == 0) cerr << "division by 0" << endl;
	return mpow(a, md-2);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	ll a, b;
	cin >> a >> b;
	ll p = a * inv(b) % md;

	vector<vector<ll>> smem(2010);
	rep(i,0,2010) smem[i].resize(i+1,-1);

	function<ll(int,int)> sum = [&](int n, int k){
		//0 <= k <= n
		if(smem[n][k] == -1){
			ll ans;
			if(k == 0 || k == n) ans = 1;
			else
				ans = (mpow(p, n-k)*sum(n-1, k-1) + mpow(1-p, k)*sum(n-1,k))%md;
			smem[n][k] = ans;
		}
		return smem[n][k];
	};

	vector<vector<ll>> pmem(2010);
	rep(i,0,2010) pmem[i].resize(i+1,-1);
	function<ll(int,int)> prob = [&](int n, int k){
		if(k <= 0 || k > n) return 0LL;
		if(pmem[n][k] == -1){
			ll ans;
			if(k == n){
				ans = 1;
				rep(i,1,n) ans -= prob(n,i);
				ans %= md;
				if(ans < 0) ans += md;
			} else {
				ans = prob(k,k)*sum(n,k)%md;
			}
			pmem[n][k] = ans;
		}
		return pmem[n][k];
	};

	vector<ll> fmem(2010,-1);

	function<ll(int)> f = [&](int n){
		if(n <= 1) return 0LL;
		if(fmem[n] != -1) return fmem[n];
		ll c = 0;
		c = (c + n*(n-1)/2)%md;
		rep(k,1,n) c = (c + prob(n, k)*(f(k) + f(n-k) - (n-k)*(n-k-1)/2))%md;

		ll ans = c * inv(1 - prob(n,n));
		ans %= md;
		if(ans < 0) ans += md;

		return fmem[n] = ans;

	};

	cout << f(n) << endl;
}