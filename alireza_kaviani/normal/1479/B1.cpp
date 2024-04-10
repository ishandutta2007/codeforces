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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n ,  A[MAXN] , seg[MAXN << 2] , lz[MAXN << 2];

void shift(int id){
	lz[lc] += lz[id];
	lz[rc] += lz[id];
	seg[lc] += lz[id];
	seg[rc] += lz[id];
	lz[id] = 0;
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

void add(int ql , int qr , int x , int id = 1 , int l = 0 , int r = MAXN){
	if(qr <= l || r <= ql)	return;
	if(ql <= l && r <= qr){
		lz[id] += x;
		seg[id] += x;
		return;
	}
	shift(id);
	int mid = l + r >> 1;
	add(ql , qr , x , lc , l , mid);
	add(ql , qr , x , rc , mid , r);
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

	add(1 , MAXN , -MOD);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
	}
	for(int i = 1 ; i <= n ; i++){
		int cost = (A[i] != A[i - 1]);
		//if(cost)	add(0 , MAXN);
		int val = max({get(0 , A[i]) + 1 , get(A[i] , A[i] + 1) , get(A[i] + 1 , MAXN) + 1});
		//cout << i << sep << val << endl;
		if(cost)	add(0 , MAXN , 1);
		modify(A[i - 1] , val);
	}
	cout << get(0 , MAXN) << endl;

    return 0;
}
/*

*/