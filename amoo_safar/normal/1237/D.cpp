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
const int Maxn = 3e5 + 10;
const int Maxm = 86500;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

pll seg[4 * Maxn];
ll lz[4 * Maxn];

void upd(int id, ll x){
	seg[id].F += x;
	lz[id] += x;
}
void shift(int id){
	upd(id << 1, lz[id]);
	upd(id << 1 | 1, lz[id]);
	lz[id] = 0;
}
void build(int id, int L, int R){
	if(L + 1 == R){
		seg[id] = {Inf, L};
		return ;
	}
	int mid = (L + R) >> 1;
	build(id << 1, L, mid);
	build(id << 1 | 1, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}
void add(int id, int l, int r, ll x, int  L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		upd(id, x);
		return ;
	}
	shift(id);
	int mid = (L + R) >> 1;
	add(id << 1, l, r, x, L, mid);
	add(id << 1 | 1, l, r, x, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

ll a[Maxn], ans[Maxn];
ll b[Maxn];

stack<ll> A, B;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	build(1, 0, Maxn);
	memset(ans, -1, sizeof ans);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i + n + n] = a[i + n] = a[i];
		b[i] = b[i + n] = b[i + n + n] = a[i];
	}
	a[0]= Inf;
	b[0] = -Inf;
	ll m = n + n + n;
	
	A.push(0);
	B.push(0);
	ll idx;
	for(int i = 1; i <= m; i++){
		
		add(1, 1, i, a[i] + a[i], 0, Maxn);
		
		while(seg[1].F < 0){
			ll mn = seg[1].S;
			ans[mn] = i - mn;
			add(1, mn, mn + 1, Inf, 0, Maxn);
		}
		
		add(1, 1, i, -a[i] -a[i], 0, Maxn);
		
		
		add(1, i, i + 1, -Inf - a[i], 0, Maxn);
		
		while(a[A.top()] <= a[i]){
			idx = A.top();
			A.pop();
			add(1, A.top() + 1, idx + 1, a[idx] - a[i], 0, Maxn);
		}
		A.push(i);
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}