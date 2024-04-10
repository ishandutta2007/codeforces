#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())
#define lc							id << 1
#define rc							lc | 1

const ll MAXN = 4e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll poww(ll x , ll y){
	ll ans = 1;
	for(; y ; y >>=1 , x = x * x % MOD)	if(y & 1)	ans = ans * x % MOD;
	return ans;
}

int q , n , m , cnt , lz[MAXN << 2];
ll fact[MAXN] , inv[MAXN];
pii seg[MAXN << 2];
vector<int> vec , sec;

void build(int id = 1 , int l = 0 , int r = m){
	lz[id] = 0;
	if(r - l == 1){
		seg[id] = {vec[l] , -l};
		return;
	}
	int mid = l + r >> 1;
	build(lc , l , mid);
	build(rc , mid , r);
	seg[id] = min(seg[lc] , seg[rc]);
}

void shift(int id){
	lz[lc] += lz[id]; seg[lc].X += lz[id];
	lz[rc] += lz[id]; seg[rc].X += lz[id];
	lz[id] = 0;
}

void add(int ql , int qr , int x , int id = 1 , int l = 0 , int r = m){
	if(qr <= l || r <= ql)	return;
	if(ql <= l && r <= qr){
		lz[id] += x;
		seg[id].X += x;
		return;
	}
	shift(id);
	int mid = l + r >> 1;
	add(ql , qr , x , lc , l , mid);
	add(ql , qr , x , rc , mid , r);
	seg[id] = min(seg[lc] , seg[rc]);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	fact[0] = 1;
	for(int i = 1 ; i < MAXN ; i++)	fact[i] = fact[i - 1] * i % MOD;
	inv[MAXN - 1] = poww(fact[MAXN - 1] , MOD - 2);
	for(int i = MAXN - 2 ; i >= 0 ; i--)	inv[i] = inv[i + 1] * (i + 1) % MOD;
	cin >> q;
	while(q--){
		cin >> n >> m; int k = 2 * n - 1;
		int prv = 0; vec.clear(); sec.clear();
		for(int i = 0 ; i < m ; i++){
			int x , y;
			cin >> x >> y;
			vec.push_back(y);
			sec.push_back(x);
			prv = x;
		}
		if(prv != n){
			vec.push_back(n);
			sec.push_back(n);
		}
		m = SZ(vec);
		build();
		prv = -1;
		int prv2 = 0 , tot = 0;
		for(int i = 0 ; i < m ; i++){
			int ind = -seg[1].Y;
			int val = seg[1].X;
			if(ind < prv || (i > 0 && val != prv2 + 1 && tot < sec[i - 1] - i))	k--;
//			cout << i << sep << val << sep << prv2 << sep << tot << endl;
			prv = ind;
			tot += val - prv2 - 1;
			prv2 = val;
			add(0 , ind , 1);
			add(ind , ind + 1 , MOD);
		//	cout << i << sep << ind << endl;
		}
		if(tot < sec.back() - m)	k--;
//		cout << k << endl;
		cout << fact[k] * inv[n] % MOD * inv[k - n] % MOD << endl;
	}

    return 0;
}
/*

*/