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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , A[MAXN] , pos[MAXN] , lisL[MAXN] , lisR[MAXN] , seg[MAXN << 2];

void modify(int pos , int val , int id = 1 , int l = 0 , int r = n){
	if(r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = l + r >> 1;
	if(pos < mid)	modify(pos , val , lc , l , mid);
	else	modify(pos , val , rc , mid , r);
	seg[id] = (seg[lc] + seg[rc]) % MOD;
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = n){
	if(qr <= l || r <= ql)	return 0;
	if(ql <= l && r <= qr)	return seg[id];
	int mid = l + r >> 1;
	return (get(ql , qr , lc , l , mid) + get(ql , qr , rc , mid , r)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		vector<pii> compress;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			compress.push_back({A[i] , -i});
			lisL[i] = lisR[i] = 0;
		}
		sort(all(compress));
		for(int i = 0 ; i < n ; i++){
			A[i] = lower_bound(all(compress) , pii(A[i] , -i)) - compress.begin();
			pos[A[i]] = i;
		}
		fill(seg , seg + 4 * n , 0);
		for(int i = 0 ; i < n ; i++){
			lisL[i] = (get(0 , A[i]) + 1) % MOD;
			modify(A[i] , lisL[i]);
//			cout << i << sep << lisL[i] << endl;
		}
		fill(seg , seg + 4 * n , 0);
		int mx = n - 1;
		for(int i = n - 2 ; i >= 0 ; i--){
			if(pos[i] > pos[mx]){
				for(int j = i ; j <= mx ; j++){
					modify(pos[j] , 0);
				}
				for(int j = mx ; j > i ; j--){
					modify(pos[j] , (get(pos[j] , n) + 1) % MOD);
				}
				mx = i;
			}
			else{
				lisR[pos[i]] = (get(pos[i] , n) + 1) % MOD;
				modify(pos[i] , lisR[pos[i]]);
			}
		}
		ll ans = 0;
		for(int i = 0 ; i < n ; i++){
			ans += 1ll * lisL[i] * lisR[i] % MOD;
		}
		cout << ans % MOD << endl;
//		cout << "=========" << endl;
	}

    return 0;
}
/*

*/