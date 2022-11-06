#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll md = 1e9+7;

ll inv(ll a, ll b = md){
	return a>1 ? b - inv(b%a, a) * b / a : 1ll;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi as(n);
	trav(a, as) cin >> a;

	vector<vi> isum(n, vi(n));
	rep(i,0,n) rep(j,0,n) isum[i][j] = inv(as[i] + as[j]);

	auto pcut = [&](int w, int l){
		ll res = 1;
		while(w){
			int i = __builtin_ctz(w);
			w -= 1<<i;
			int ll = l;
			while(ll){
				int j = __builtin_ctz(ll);
				ll -= 1<<j;
				res = (res * as[i]) % md;
				res = (res * isum[i][j]) % md;
			}
		}
		return res;
	};

	vector<ll> pgood(1<<n, 1);
	pgood[0] = 0;
	ll ans = 0;
	rep(msk,1,1<<n){
		for(int sub = msk; ;){
			sub = (sub - 1) & msk;
			pgood[msk] = (pgood[msk] - pgood[sub] * pcut(sub, msk ^ sub)) % md;
			if(sub == 0) break;
		}
		ans = (ans + __builtin_popcount(msk) * pgood[msk] % md * pcut(msk, ((1<<n)-1)^msk)) % md;
	}
	if(ans < 0) ans += md;
	cout << ans << endl;
}