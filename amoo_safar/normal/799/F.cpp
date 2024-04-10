// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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

struct node {
	int lz, mn, cnt;
	ll sum;
	node (){
		lz = 0, mn = 0, cnt = 0, sum = 0;
	}
};

node base;
node seg[N << 2];

node Merge(node& a, node& b){
	node res;
	res.mn = min(a.mn, b.mn);
	if(res.mn == a.mn){
		res.cnt += a.cnt;
		res.sum += a.sum;
	}
	if(res.mn == b.mn){
		res.cnt += b.cnt;
		res.sum += b.sum;
	}
	return res;
}
void Apply(int id, int x){
	seg[id].lz += x;
	seg[id].mn += x;
}
void Shift(int id){
	Apply(id << 1, seg[id].lz);
	Apply(id << 1 | 1, seg[id].lz);
	seg[id].lz = 0;
}
void Build(int id, int L, int R){
	if(L + 1 == R){
		seg[id].mn = 0;
		seg[id].lz = 0;
		seg[id].sum = L;
		seg[id].cnt = 1;
		return ;
	}
	int mid = (L + R) >> 1;
	Build(id << 1, L, mid);
	Build(id << 1 | 1, mid, R);
	seg[id] = Merge(seg[id << 1], seg[id << 1 | 1]);
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
	Add(id << 1 | 1, l, r, x, mid, R);
	seg[id] = Merge(seg[id << 1], seg[id << 1 | 1]);
}

int n, a[N], b[N];
vector< pair<pll, pair<pll, pll>> > V; // 01 lx,rx ly,ry
vector< pair<pll, int>> E[N];

int ps[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m;
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		a[i] --;
		ps[a[i]] ++;
		ps[b[i]] --;

		V.pb({{0, 0}, {{a[i], b[i] + 1}, {a[i], b[i] + 1}}});
		V.pb({{1, 1}, {{a[i], b[i] + 1}, {a[i], b[i] + 1}}});
		
		V.pb({{0, a[i] & 1}, {{0, a[i]}, {a[i] + 1, b[i] + 1}}});
		V.pb({{1, a[i] & 1}, {{0, a[i]}, {a[i] + 1, b[i] + 1}}});
		
		V.pb({{b[i] & 1, 0}, {{a[i], b[i]}, {b[i] + 1, n + 1}}});
		V.pb({{b[i] & 1, 1}, {{a[i], b[i]}, {b[i] + 1, n + 1}}});	
		if((a[i] - b[i]) % 2 == 0){
			V.pb({{0, 0}, {{0, a[i]}, {b[i] + 1, n + 1}}});
			V.pb({{0, 1}, {{0, a[i]}, {b[i] + 1, n + 1}}});
			V.pb({{1, 0}, {{0, a[i]}, {b[i] + 1, n + 1}}});
			V.pb({{1, 1}, {{0, a[i]}, {b[i] + 1, n + 1}}});
		}
	}
	for(int i = 1; i < n; i++) ps[i] += ps[i - 1];
	ll ans = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		if(ps[i] == 0) cnt ++;
		else cnt = 0;
		ans -= (cnt * (cnt + 1)) / 2ll;
	}
	for(int b1 = 0; b1 < 2; b1 ++) for(int b2 = 0; b2 < 2; b2 ++){
		Build(1, 0, n + 1);
		for(int i = 0; i < N; i++) E[i].clear();
		for(auto &rec : V){
			if(rec.F != pll(b1, b2)) continue;
			E[rec.S.F.F].pb({rec.S.S, 1});
			E[rec.S.F.S].pb({rec.S.S, -1});
		}
		for(int i = 0; i <= n; i++){
			if((i & 1) != b2) Add(1, i, i + 1, 1, 0, n + 1);
		}
		for(int i = 0; i < n; i++){
			Add(1, i, i + 1, 1, 0, n + 1);
			for(auto &x : E[i]){
				Add(1, x.F.F, x.F.S, x.S, 0, n + 1);
			}
			assert(seg[1].mn >= 0);
			if(seg[1].mn == 0 && ((i & 1) == b1)){
				ans += seg[1].sum - (1ll * seg[1].cnt * i);
				//cerr << b1 << ' ' << b2 << ' ' << i << ' ' << seg[1].sum - (seg[1].cnt * i) << '\n';
			}
		}
		//cout << ans << '\n';
	}
	cout << ans << '\n';
	return 0;
}