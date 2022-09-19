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

ll dp[N];

int a[N];
map<ll, ll> mp;

int Main(){
	int L, R;
	cin >> L >> R;
	vector< pair<pll, ll> > E;

	int n = 32;
	E.pb({{31, 32}, 1});
	ll rn = 1;
	for(int i = 30; i >= 1; i--){
		rn *= 2;
		if(rn >= 1000000) break;
		E.pb({{i, 32}, 1});
		ll RR = 1;
		for(int j = 31; j > i; j--){
			E.pb({{i, j}, RR});
			RR *= 2;
		}
	}
	int nd = (L == 1 ? 1 : 2);
	if(L != 1){
		E.pb({{1, 2}, L - 1});
		R -= L - 1;
		L = 1;
	}
	E.pb({{nd, 32}, 1});
	// for(int i = 0; i < n; i++){
		ll rg = 1;

		for(int j = 0; j < 20; j++){
			if((R - 1) >> j & 1){
				debug(j);
				E.pb({{nd, 31 - j}, rg});
				rg += (1ll << j);
			}
		}
		debug(rg);
		debug(R);
	// }
	cout << "YES\n32 " << E.size() << '\n';
	for(auto X : E){
		cout << X.F.F << ' ' << X.F.S << ' ' << X.S << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T --) Main();
	return 0;
}