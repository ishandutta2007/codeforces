#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e5 + 10;
const int Maxm = 86500;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int seg[Maxn << 2];
void change(int id, int i, int x, int L, int R){
	if((i < L) || (R <= i)) return ;
	if((L + 1 == R) && (L == i)){
		seg[id] = x;
		return ;
	}
	
	int mid = (L + R) >> 1;
	change(id << 1, i, x, L, mid);
	change(id << 1 | 1, i, x, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}
int get(int id, int l, int r, int L, int R){
	if((r <= L) || (R <= l)) return Maxn;
	if((l <= L) && (R <= r)) return seg[id];
	int mid = (L + R) >> 1;
	return min(get(id << 1, l, r, L, mid), get(id << 1 | 1, l, r, mid, R));
}

bool ans[Maxn << 1];

vector<int> rx[Maxn], ry[Maxn];
vector< pair<pll, pll> > Qx[Maxn], Qy[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k, q;
	cin >> n >> m >> k >> q;
	ll x1, y1, x2, y2;
	for(int i = 0; i < k; i++){
		cin >> x1 >> y1;
		rx[x1].pb(y1);
		ry[y1].pb(x1);
	}
	for(int i = 0; i < q; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		Qx[x2].pb({{y1, y2 + 1}, {x1, i}});
		Qy[y2].pb({{x1, x2 + 1}, {y1, i}});
	}
	
	memset(seg, -1, sizeof seg);
	for(int i = 1; i <= n; i++){
		for(auto r : rx[i]) change(1, r, i, 1, Maxn);
		for(auto Q : Qx[i]) ans[Q.S.S] |= (Q.S.F <= get(1, Q.F.F, Q.F.S, 1, Maxn));
	}
	
	memset(seg, -1, sizeof seg);
	for(int i = 1; i <= m; i++){
		for(auto r : ry[i]) change(1, r, i, 1, Maxn);
		for(auto Q : Qy[i]) ans[Q.S.S] |= (Q.S.F <= get(1, Q.F.F, Q.F.S, 1, Maxn));
	}
	
	for(int i = 0; i < q; i++) cout << (ans[i] ? "YES\n" : "NO\n");
	return 0;
}