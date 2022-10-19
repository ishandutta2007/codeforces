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
#define lc			id << 1
#define rc			lc | 1

const ll MAXN = 4e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , m , N , A[MAXN] , K[MAXN] , seg[MAXN << 2] , lz[MAXN << 2];
ll sum[MAXN];
vector<int> vec[MAXN];
vector<pll> compress;

pll Div(ll x , ll y){
	ll g = __gcd(x , y);
	return {x / g , y / g};
}

int cmp(pll x , pll y){
	return x.X * y.Y < x.Y * y.X;
}

int value(ll x , ll y){
	pll A = Div(x , y);
	int ind = lower_bound(all(compress) , A , cmp) - compress.begin();
	return ind;
}

void shift(int id){
	lz[lc] += lz[id]; seg[lc] += lz[id];
	lz[rc] += lz[id]; seg[rc] += lz[id];
	lz[id] = 0;
}

void add(int ql , int qr , int val , int id = 1 , int l = 0 , int r = N){
	if(qr <= l || r <= ql)	return;
	if(ql <= l && r <= qr){
		seg[id] += val;
		lz[id] += val;
		return;
	}
	shift(id);
	int mid = l + r >> 1;
	add(ql , qr , val , lc , l , mid);
	add(ql , qr , val , rc , mid , r);
	seg[id] = min(seg[lc] , seg[rc]);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m;
		compress.clear();
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			compress.push_back({A[i] , 1});
		}
		for(int i = 0 ; i < m ; i++){
			vec[i].clear();
			cin >> K[i]; sum[i] = 0;
			for(int j = 0 ; j < K[i] ; j++){
				int x;
				cin >> x;
				sum[i] += x;
				vec[i].push_back(x);
			}
			compress.push_back(Div(sum[i] , K[i]));
			for(int j = 0 ; j < K[i] ; j++){
				compress.push_back(Div(sum[i] - vec[i][j] , K[i] - 1));
			}
		}
		sort(all(compress) , cmp);
		compress.resize(unique(all(compress)) - compress.begin());
		N = SZ(compress);
		fill(seg , seg + N * 4 , 0);
		fill(lz , lz + N * 4 , 0);
		for(int i = 0 ; i < n ; i++){
		//	cout << i << sep << value(A[i] , 1) << endl;
			add(0 , value(A[i] , 1) + 1 , 1);
		}
		for(int i = 0 ; i < m ; i++){
			add(0 , value(sum[i] , K[i]) + 1 , -1);
		}
		for(int i = 0 ; i < m ; i++){
			add(0 , value(sum[i] , K[i]) + 1 , 1);
			for(int j = 0 ; j < K[i] ; j++){
		//		cout << i << sep << j << sep << value(sum[i] - vec[i][j] , K[i] - 1) << endl;
				add(0 , value(sum[i] - vec[i][j] , K[i] - 1) + 1 , -1);
				cout << (seg[1] < 0 ? 0 : 1);
				add(0 , value(sum[i] - vec[i][j] , K[i] - 1) + 1 , 1);
			}
			add(0 , value(sum[i] , K[i]) + 1 , -1);
		}
		cout << endl;
	}

    return 0;
}
/*

*/