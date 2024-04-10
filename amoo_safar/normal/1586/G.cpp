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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


struct FenwickTree {
	using T = ll;
	T fen[N];
	int n = N;
	FenwickTree (){
		memset(fen, 0, sizeof fen);
	}
	void Add(int idx, T x){
		for(; idx < n; idx += (idx & (-idx)))
			(fen[idx] += x) %= Mod;
	}
	T Get(int idx){
		T res = 0;
		for(; idx; idx -= (idx & (-idx)))
			res += fen[idx];
		return res % Mod;
	}
};
FenwickTree DS;

int a[N], b[N], dp[N];
ll mx[N];

int Main(){
	int n;
	cin >> n;
	
	vector<int> V;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		V.pb(i);
	}
	sort(all(V), [&](int i, int j){
		return a[i] > a[j];
	});
	ll ans = 0;
	
	ll q;
	cin >> q;
	int u;
	for(int i = 0; i < q; i++){
		cin >> u; u--;
		mx[a[u]] = b[u];
		ans += dp[u - 1];
		ans %= Mod;
	}
	for(int i = n + n; i >= 0; i--) mx[i] = max(mx[i], mx[i + 1]);

	for(int i = 0; i < n; i++){
		int ii = V[i];
		ll res = Mod + 1 + /*DS.Get(N - 2) - */  DS.Get(b[ii]);
		// debug(DS.Get(N - 2));
		res %= Mod;

		DS.Add(b[ii], res);
		dp[ii] = res;
		// debug(b[ii]);
		// debug(res);
		// debug(dp[ii]);
		if(mx[a[ii]] >= b[ii])ans += dp[ii];
	}
	cout << ans % Mod << '\n';
	// ans = 0;
	// cout << ans % Mod << '\n';
	return 0;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T --) Main();
	return 0;
}