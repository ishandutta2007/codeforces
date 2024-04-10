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
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 4e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int seg[N << 2], lz[N << 2];
void Apply(int id, int x){
	seg[id] += x;
	lz[id] += x;
}
void Shift(int id){
	Apply(id << 1, lz[id]);
	Apply(id << 1|1, lz[id]);
	lz[id] = 0;
}
void Add(int id, int l, int r, int x, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		Apply(id, x);
		return ;
	}
	Shift(id);
	int mid = (L + R) >> 1;
	Add(id << 1, l, r, x, L, mid);
	Add(id<<1|1, l, r, x, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

bool Less(pll A, pll B){
	return A.F * B.S < A.S * B.F;
}
int b[N];
int Main(){
	int n, m;
	cin >> n >> m;
	vector< pll > V, T, G;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		V.pb({a, 1});
		T.pb(V.back());
	}
	int sz;
	vector< pair<pll, pll> > X;
	for(int i = 0; i < m; i++){
		cin >> sz;
		ll sm = 0;
		for(int j = 0; j < sz; j++){
			cin >> b[j];
			sm += b[j];
		}
		V.pb({sm, sz});
		G.pb(V.back());
		for(int j = 0; j < sz; j++){
			sm -= b[j];
			V.pb({sm, sz - 1});
			sm += b[j];
			X.pb({V.back(), {sm, sz}});
		}
	}
	sort(all(V), Less);
	function<int(pll)> Find = [&](pll A){
		int L = -1, R = V.size(), mid;
		while(L + 1 < R){
			mid = (L + R) >> 1;
			if(Less(A, V[mid])) R = mid;
			else L = mid;
		}
		return L + 1;
	};
	for(auto &el : T) Add(1, 0, Find(el), +1, 0, N);
	for(auto &el : G) Add(1, 0, Find(el), -1, 0, N);
		// for(auto x : T) debug(Find(x));
		// for(auto x : G) debug(Find(x)+0);
	// debug(seg[1]);
	for(auto [ad, rm] : X){
		int a = Find(ad), b = Find(rm);
		// cerr << "!!! " << a << ' ' << b << '\n';
		Add(1, 0, a, -1, 0, N);
		Add(1, 0, b, +1, 0, N);
		// cerr << "??? " << seg[1] << '\n';
		cout << (seg[1] < 0 ? 0 : 1);
		Add(1, 0, a, +1, 0, N);
		Add(1, 0, b, -1, 0, N);
		
	}
	
	for(auto &el : T) Add(1, 0, Find(el), -1, 0, N);
	for(auto &el : G) Add(1, 0, Find(el), +1, 0, N);

	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}