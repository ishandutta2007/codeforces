#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<pll, pll> Node;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())
#define lc          id << 1
#define rc          lc | 1

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 2e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , q , D[MAXN] , H[MAXN] , ps[MAXN];
Node seg[2][MAXN << 2];

Node merge(Node x , Node y){
	x.Y = max(x.Y , y.X);
	if(x.Y > x.X)	swap(x.X , x.Y);
	x.Y = max(x.Y , y.Y);
	if(x.Y > x.X)	swap(x.X , x.Y);
	return x;
}

void build(int id = 1 , int l = 0 , int r = n + n){
	if(r - l == 1){
		seg[0][id] = {{2 * H[l] - ps[l] , l % n} , {-INF , -INF}};
		seg[1][id] = {{2 * H[l] + ps[l] , l % n} , {-INF , -INF}};
		return;
	}
	int mid = l + r >> 1;
	build(lc , l , mid);
	build(rc , mid , r);
	seg[0][id] = merge(seg[0][lc] , seg[0][rc]);
	seg[1][id] = merge(seg[1][lc] , seg[1][rc]);
}

Node get(int ind , int ql , int qr , int id = 1 , int l = 0 , int r = n + n){
	if(qr <= l || r <= ql)	return seg[ind][0];
	if(ql <= l && r <= qr)	return seg[ind][id];
	int mid = l + r >> 1;
	return merge(get(ind , ql , qr , lc , l , mid) , get(ind , ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	for(int i = 0 ; i < n ; i++){
		cin >> D[i];
		D[i + n] = D[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin >> H[i];
		H[i + n] = H[i];
	}
	for(int i = 0 ; i < n + n ; i++){
		ps[i + 1] = ps[i] + D[i];
//		cout << i << sep << H[i] << sep << ps[i] << endl;
	}
	build(); seg[0][0] = seg[1][0] = {{-INF , -INF} , {-INF , -INF}};
	while(q--){
		int r , l;
		cin >> r >> l; r--; l--;
		if(r <= l)	r += n;
		l++;
		Node L = get(0 , l , r) , R = get(1 , l , r);
//		cout << L.X.X << sep << L.Y.X << sep << R.X.X << sep << R.Y.X << endl;
//		cout << L.X.Y << sep << L.Y.Y << sep << R.X.Y << sep << R.Y.Y << endl;
		ll ans = -INF;
		if(L.X.Y != R.X.Y)	ans = max(ans , L.X.X + R.X.X);
		if(L.X.Y != R.Y.Y)	ans = max(ans , L.X.X + R.Y.X);
		if(L.Y.Y != R.X.Y)	ans = max(ans , L.Y.X + R.X.X);
		cout << ans << endl;
	}

    return 0;
}
/*

*/