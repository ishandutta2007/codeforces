#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;

ull cur = 123123181LL;

ull rnd(){
	cur ^= 213498349281LL;
	cur *= 12341341432LL;
	cur ^= cur >> 32;
	return cur & ((1LL<<25) - 1);
}

int pos(ll x){
	return 61 - __builtin_clzll(x);
}

ll fun(ll a, ll b, vector<pii> &res){
	while(a){
		int dif = pos(a) - pos(b);
		if(dif < 0) break;
		res.emplace_back(a, b << dif);
		a ^= b << dif;
	}
	return a;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	vector<pair<pii, char>> ans;

	ll x;
	cin >> x;

	while(x > 1){
		vector<pii> junk;
		ll y;
		ll res;
		do {
			y = rnd();
			junk.clear();
			res = fun(y*x, x, junk);
		} while(res % 2 == 0);

		for(int i = 0; y >= (1LL << i); ++i){
			ans.emplace_back( pii(x<<i, x<<i), '+');
		}

		for(int i = 1; y >= (1LL<<i); ++i){
			ll r = y & ((1LL<<i)-1);
			if(r && (y & (1LL<<i))){
				ans.emplace_back( pii(x << i, x * r), '+');
			}
		}

		trav(pa, junk){
			ans.emplace_back(pa, '^');
		}
		
		x = res;
	}
	cout << sz(ans) << endl;
	trav(t, ans){
		cout << t.first.first << " " << t.second << " " << t.first.second << endl;		
	}
}