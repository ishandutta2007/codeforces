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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , cnt , GCD , A[MAXN] , B[MAXN] , seg[MAXN << 2];

void build(int id = 1 , int l = 1 , int r = n){
	if(r - l == 1){
		seg[id] = B[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc , l , mid);
	build(rc , mid , r);
	seg[id] = __gcd(seg[lc] , seg[rc]);
}

int get(int x , int id = 1 , int l = 1 , int r = n){
	if(r <= x)	return 1;
	if(x <= l){
		if(__gcd(GCD , seg[id]) > 1){
			cnt += r - l;
			GCD = __gcd(seg[id] , GCD);
			return 1;
		}
	}
	if(r - l == 1)	return 0;
	int mid = l + r >> 1;
	if(get(x , lc , l , mid))	return get(x , rc , mid , r);
	return 0;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 1 ; i <= n ; i++)	cin >> A[i];
		for(int i = 1 ; i < n ; i++)	B[i] = abs(A[i] - A[i + 1]);
		if(n == 1){
			cout << 1 << endl;
			continue;
		}
		build();
		ll ans = 0;
		for(int i = 1 ; i < n ; i++){
			cnt = 0; GCD = 0; get(i);
			ans = max(ans , cnt);
		}
		cout << ans + 1 << endl;
	}

    return 0;
}
/*

*/