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

ll n , q , A[MAXN] , B[MAXN] , ps[MAXN] , mn[MAXN << 2] , mx[MAXN << 2];

void build(int id = 1 , int l = 0 , int r = n + 1){
	if(r - l == 1){
		mn[id] = ps[l];
		mx[id] = ps[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc , l , mid);
	build(rc , mid , r);
	mn[id] = min(mn[lc] , mn[rc]);
	mx[id] = max(mx[lc] , mx[rc]);
}

ll getMax(int ql , int qr , int id = 1 , int l = 0 , int r = n + 1){
	if(qr <= l || r <= ql)	return -INF;
	if(ql <= l && r <= qr)	return mx[id];
	int mid = l + r >> 1;
	return max(getMax(ql , qr , lc , l , mid) , getMax(ql , qr , rc , mid , r));
}

ll getMin(int ql , int qr , int id = 1 , int l = 0 , int r = n + 1){
	if(qr <= l || r <= ql)	return INF;
	if(ql <= l && r <= qr)	return mn[id];
	int mid = l + r >> 1;
	return min(getMin(ql , qr , lc , l , mid) , getMin(ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> B[i];
		ps[i] = B[i] - A[i];
	}
	partial_sum(ps , ps + MAXN , ps);
	build();
	while(q--){
		int l , r;
		cin >> l >> r; l--;
		if(ps[l] != ps[r] || getMin(l + 1 , r + 1) < ps[l]){
			cout << -1 << endl;
			continue;
		}
		cout << getMax(l + 1 , r + 1) - ps[l] << endl;
	}

    return 0;
}
/*

*/