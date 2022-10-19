#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())
#define lc          id << 1
#define rc          lc | 1

const ll MAXN = 2e5 + 10;
const ll MAXA = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , q , A[MAXN] , ans[MAXN] , mark[MAXA] , prv[MAXA] , lz[MAXN << 2];
vector<pii> vec , Q[MAXN];
vector<int> dv[MAXA];

void update(int ql , int qr , ll x , int id = 1 , int l = 0 , int r = n){
	if(qr <= l || r <= ql)	return;
	if(ql <= l && r <= qr){
		lz[id] = lz[id] * x % MOD;
		return;
	}
	int mid = l + r >> 1;
	update(ql , qr , x , lc , l , mid);
	update(ql , qr , x , rc , mid , r);
}

ll get(int pos , int id = 1 , int l = 0 , int r = n){
	if(r - l == 1)	return lz[id];
	int mid = l + r >> 1;
	if(pos < mid)	return lz[id] * get(pos , lc , l , mid) % MOD;
	return lz[id] * get(pos , rc , mid , r) % MOD;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(lz , lz + MAXN * 4 , 1);
	fill(prv , prv + MAXA , -1);

	for(int i = 2 ; i < MAXA ; i++){
		if(mark[i])	continue;
		for(int j = i ; j < MAXA ; j += i){
			mark[j] = 1;
			int x = j;
			while(x % i == 0){
				dv[j].push_back(i);
				x /= i;
			}
		}
	}

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
	}
	cin >> q;
	for(int i = 0 ; i < q ; i++){
		int l , r;
		cin >> l >> r; l--; r--;
		Q[r].push_back({l , i});
	}
	for(int i = 0 ; i < n ; i++){
		for(int j : dv[A[i]]){
//			cout << i << sep << j << endl;
			update(prv[j] + 1 , i + 1 , j - 1);
			update(0 , prv[j] + 1 , j);
			prv[j] = i;
		}
		for(pii j : Q[i]){
			ans[j.Y] = get(j.X);
		}
	}
	for(int i = 0 ; i < q ; i++){
		cout << ans[i] << endl;
	}

	return 0;
}
/*

*/