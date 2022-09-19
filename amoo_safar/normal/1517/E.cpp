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

const ll Mod = 998244353ll;
const int N = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


ll a[N];
ll e1[N], e2[N];
ll s1[N], s2[N];
ll ps[N];


struct Fen {
	int fen[N];
	int _N = N;

	vector<ll> V;
	Fen (){
		memset(fen, 0, sizeof fen);
	}
	void Ins(ll x){
		V.pb(x);
	}
	void Build(){
		sort(all(V));
		_N = V.size() + 5;
		fill(fen, fen + _N, 0);
	}
	void Add(int idx){
		for(; idx < _N; idx += (idx & (-idx)))
			fen[idx] ++;
	}
	int Get(int idx){
		// debug(idx);
		assert(idx > 0);
		int res = 0;
		for(; idx; idx -= (idx & (-idx)))
			res += fen[idx];
		return res;
	}
	void On(ll x){
		// debug(x);
		int id = lower_bound(all(V), x) - V.begin();
		// debug(id);
		Add(id + 3);
	}
	int Less(ll x){
		int id = lower_bound(all(V), x) - V.begin();
		// debug(id);
		return Get((id + 3) - 1);
	}

};
Fen DS[2];

int Main(){
	DS[0].V.clear();
	DS[1].V.clear();
	int n;
	cin >> n;

	fill(ps, ps + n + 2, 0);
	fill(e1, e1 + n + 2, 0);
	fill(e2, e2 + n + 2, 0);
	fill(s1, s1 + n + 2, 0);
	fill(s2, s2 + n + 2, 0);
	

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	e1[n] = 0;
	for(int i = n - 1; i >= 0; i--)
		e1[i] = e1[i + 1] - a[i];
	e2[n] = Inf;

	e2[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--)
		e2[i] = e2[i + 1] - a[i];
	e2[n - 1] = e2[n];
	e2[n - 2] = e2[n];

	s1[0] = 0;
	for(int i = 1; i <= n; i++)
		s1[i] = s1[i - 1] + a[i - 1];
	s2[1] = -a[0];
	for(int i = 2; i <= n; i++)
		s2[i] = s2[i - 1] + a[i - 1];
	s2[0] = s2[1] = Inf;


	for(int i = 2; i <= n; i++){
		ps[i] = ps[i - 2] + a[i - 1] - a[i - 2];
	}
	// debug()
	// debug("SS");
	for(int i = 0; i <= n; i++){
		DS[i & 1].Ins(ps[i] + e1[i]);
		DS[i & 1].Ins(ps[i] + e2[i]);
	}
	// debug("A");
	DS[0].Build();
	DS[1].Build();
	// debug("B");
	ll ans = 1;
	// debug(n);
	for(int i = n; i >= 1; i-=1){
		// debug(i);
		DS[i & 1].On(e1[i] + ps[i]);
		DS[i & 1].On(e2[i] + ps[i]);
		// cerr << "!! " << e1[i] + ps[i] << " " << e2[i] + ps[i] << '\n';
		// debug(i);
		if(i != n){
			// debug(i);
			// cerr << "# "  << ans << '\n';
			
			// cerr << "?? " << s1[i] - ps[i] << " " << s2[i] - ps[i] << '\n';
			ans += DS[i & 1].Less(-(s1[i] - ps[i]));
			ans += DS[i & 1].Less(-(s2[i] - ps[i]));
			if(s1[i] + e1[i] > 0) ans ++;
		}
		// cerr << "! " << ans << '\n';
	}

	cout << ans % Mod << '\n';
	
	return 0;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc -- ) Main();
	return 0;
}