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

ll seg[N << 2];
ll lz[N << 2];
ll C[N];

void Build(int id, int L, int R){
	seg[id] = -C[L];
	lz[id] = 0;
	if(L + 1 == R) return ;
	int mid = (L + R) >> 1;
	Build(id << 1, L, mid);
	Build(id << 1 | 1, mid, R);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
	return ;
}
void Apply(int id, ll x){
	seg[id] += x;
	lz[id] += x;
}
void Shift(int id){
	Apply(id << 1, lz[id]);
	Apply(id << 1 | 1, lz[id]);
	lz[id] = 0;
}
void Add(int id, int l, int r, ll x, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		Apply(id, x);
		return ;
	}
	Shift(id);
	int mid = (L + R) >> 1;
	Add(id << 1, l, r, x, L, mid);
	Add(id << 1 | 1, l, r, x, mid, R);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
	return ;
}


vector<pll> V;
ll y[N], z[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(C, 31, sizeof C);
	ll n, m, p;
	cin >> n >> m >> p;
	ll a, c;
	for(int i = 0; i < n; i++){
		cin >> a >> c;
		V.pb({a, -c});
	}
	for(int i = 0; i < m; i++){
		cin >> a >> c;
		C[a] = min(C[a], c);
	}
	ll x;
	for(int i = 1; i <= p; i++){
		cin >> x >> y[i] >> z[i];
		V.pb({x, i});
	}
	for(int i = N-2; i >= 0; i--)C[i] = min(C[i], C[i + 1]);
	Build(1, 0, N);
	sort(all(V));
	ll ans = -Inf;

	for(auto x : V){
		if(x.S < 0){
			ans = max(ans, seg[1] + x.S);
		} else {
			ll id = x.S;
			Add(1, y[id] + 1, N, z[id], 0, N);
		}
	}
	cout << ans << '\n';
	return 0;
}