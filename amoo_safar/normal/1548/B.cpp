// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		ll la;
		cin >> la;
		ll ans = 0;
		vector<pll> V;
		for(int i = 1; i < n; i++){
			// debug(V.size());
			ll x;
			cin >> x;
			ll nw = abs(x - la);
			la = x;

			V.pb({1, nw});
			ll nw2 = nw;
			vector<pll> V2;
			while(!V.empty()){
				pll k = pll(V.back().F, __gcd(V.back().S, nw2) );
				V.pop_back();
				nw2 = k.S;
				if(!V2.empty() && V2.back().S == k.S)
					V2[V2.size() - 1].F += k.F;
				else
					V2.pb(k);
			}
			reverse(all(V2));
			V = V2;
			ll res = 0;
			for(auto x : V)
				if(x.S != 1)
					res += x.F;
			ans = max(ans, res);
		}
		cout << ans + 1 << '\n';
	}
	return 0;
}