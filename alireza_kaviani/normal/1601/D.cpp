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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , d , S[MAXN] , A[MAXN] , seg[MAXN << 2] , lz[MAXN << 2];
vector<int> compress;
vector<pair<int , pii>> vec;

void shift(int id){
	seg[lc] += lz[id]; lz[lc] += lz[id];
	seg[rc] += lz[id]; lz[rc] += lz[id];
	lz[id] = 0;
}

void update(int ql , int qr , int val , int id = 1 , int l = 0 , int r = MAXN){
	if(qr <= l || r <= ql)	return;
	if(ql <= l && r <= qr){
		seg[id] += val;
		lz[id] += val;
		return;
	}
	shift(id);
	int mid = l + r >> 1;
	update(ql , qr , val , lc , l , mid);
	update(ql , qr , val , rc , mid , r);
	seg[id] = max(seg[lc] , seg[rc]);
}

void modify(int pos , int val , int id = 1 , int l = 0 , int r = MAXN){
	if(r - l == 1){
		seg[id] = max(seg[id] , val);
		return;
	}
	shift(id);
	int mid = l + r >> 1;
	if(pos < mid)	modify(pos , val , lc , l , mid);
	else	modify(pos , val , rc , mid , r);
	seg[id] = max(seg[lc] , seg[rc]);
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
	if(qr <= l || r <= ql)	return -MOD;
	if(ql <= l && r <= qr)	return seg[id];
	shift(id);
	int mid = l + r >> 1;
	return max(get(ql , qr , lc , l , mid) , get(ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(seg , seg + MAXN * 4 , -MOD);

	cin >> n >> d;
	compress.push_back(d);
	for(int i = 1 ; i <= n ; i++){
		cin >> S[i] >> A[i];
		compress.push_back(S[i]);
		compress.push_back(A[i]);
	}
	sort(all(compress));
	compress.resize(unique(all(compress)) - compress.begin());
	d = lower_bound(all(compress) , d) - compress.begin();
	for(int i = 1 ; i <= n ; i++){
		S[i] = lower_bound(all(compress) , S[i]) - compress.begin();
		A[i] = lower_bound(all(compress) , A[i]) - compress.begin();
		vec.push_back({A[i] + S[i] , {A[i] , S[i]}});
	}
	sort(all(vec));
	modify(d , 0);
	for(pair<int , pii> i : vec){
		int a = i.Y.X , s = i.Y.Y;
		int cur = get(0 , min(a , s) + 1) + 1;
		update(a , s + 1 , 1);
		modify(a , cur);
	}
	cout << seg[1] << endl;

    return 0;
}
/*

*/