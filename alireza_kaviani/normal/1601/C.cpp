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

const ll MAXN = 2e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , m , A[MAXN] , B[MAXN] , cnt[MAXN] , seg[MAXN << 2] , lz[MAXN << 2];
vector<int> compress , pos[MAXN];

void build(int id = 1 , int l = 0 , int r = n + 1){
	lz[id] = 0;
	if(r - l == 1){
		seg[id] = l;
		return;
	}
	int mid = l + r >> 1;
	build(lc , l , mid);
	build(rc , mid , r);
	seg[id] = min(seg[lc] , seg[rc]);
}

void shift(int id){
	seg[lc] += lz[id]; lz[lc] += lz[id];
	seg[rc] += lz[id]; lz[rc] += lz[id];
	lz[id] = 0;
}

void update(int ql , int qr , int val , int id = 1 , int l = 0 , int r = n + 1){
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
	seg[id] = min(seg[lc] , seg[rc]);
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = n + 1){
	if(qr <= l || r <= ql)	return MOD;
	if(ql <= l && r <= qr)	return seg[id];
	shift(id);
	int mid = l + r >> 1;
	return min(get(ql , qr , lc , l , mid) , get(ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m;
		compress.clear(); compress.push_back(0);
		for(int i = 0 ; i <= n + m + 5 ; i++){
			cnt[i] = 0;
			pos[i].clear();
		}
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
			compress.push_back(A[i]);
		}
		for(int i = 1 ; i <= m ; i++){
			cin >> B[i];
			compress.push_back(B[i]);
		}
		sort(all(compress));
		compress.resize(unique(all(compress)) - compress.begin());
		for(int i = 1 ; i <= n ; i++){
			A[i] = lower_bound(all(compress) , A[i]) - compress.begin();
			pos[A[i]].push_back(i);
		}
		for(int i = 1 ; i <= m ; i++){
			B[i] = lower_bound(all(compress) , B[i]) - compress.begin();
			cnt[B[i]]++;
		}
		build(); ll ans = 0;
//		cout << seg[1] << endl;
		for(int i = 1 ; i <= n + m ; i++){
			for(int j : pos[i - 1]){
				update(0 , j , 1);
//				cout << "add " << i << sep << j << endl;
			}
			for(int j : pos[i]){
				update(j , n + 1 , -1);
				ans += get(j , j + 1);
//				cout << "remove " << i << sep << j << endl;
			}
			ans += 2ll * seg[1] * cnt[i];
//			cout << i << sep << ans << sep << endl;
		}
		cout << ans / 2 << endl;
//		cout << "========" << endl;
	}

    return 0;
}
/*

*/