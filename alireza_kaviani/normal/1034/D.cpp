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

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , k , m , sum , cur , ptr , A[MAXN] , B[MAXN] , L[MAXN] , cnt[MAXN];
vector<ll> compress = {0 , MOD};
vector<pii> vec[MAXN];

ll mn[MAXN << 3] , mx[MAXN << 3] , sz[MAXN << 3] , lz[MAXN << 3];
	
void build(int id = 1 , int l = 0 , int r = m){
	if(r - l == 1){
		sz[id] = compress[l + 1] - compress[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc , l , mid);
	build(rc , mid , r);
	sz[id] = sz[lc] + sz[rc];
}

void shift(int id){
	if(lz[id] == 0)	return;
	lz[lc] = mn[lc] = mx[lc] = lz[id];
	lz[rc] = mn[rc] = mx[rc] = lz[id];
	lz[id] = 0;
}

void update(int ql , int qr , int x , int id = 1 , int l = 0 , int r = m){
	if(qr <= l || r <= ql)	return;
	if(ql <= l && r <= qr && mn[id] == mx[id]){
		vec[x].push_back({mn[id] , sz[id]});
		lz[id] = mn[id] = mx[id] = x;
		return;
	}
	shift(id);
	int mid = l + r >> 1;
	update(ql , qr , x , lc , l , mid);
	update(ql , qr , x , rc , mid , r);
	mn[id] = min(mn[lc] , mn[rc]);
	mx[id] = max(mx[lc] , mx[rc]);
}

void init(){
	fill(cnt , cnt + MAXN , 0);
	sum = cur = 0; ptr = 1;
}

void calc(ll x){
	init();
	L[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		for(pii j : vec[i]){
//			cout << i << sep << j.X << sep << j.Y << endl;
			cnt[j.X] -= j.Y;
			cnt[i] += j.Y;
			if(ptr > j.X){
				sum += j.Y;
			}
		}
		while(ptr <= i && sum >= x){
			sum -= cnt[ptr];
			ptr++;
		}
		L[i] = ptr;
	}
//	cout << "============" << endl;
}

ll count(){
	ll ans = 0;
	for(int i = 0 ; i <= n ; i++){
		ans += L[i] - 1;
	}
	return ans;
}

ll solve(ll x){
	init();
	ll ans = 0;
	for(int i = 1 ; i <= n ; i++){
		L[i]--;
		for(pii j : vec[i]){
			cnt[j.X] -= j.Y;
			cnt[i] += j.Y;
			if(ptr > j.X){
				sum += j.Y;
				cur -= 1ll * j.X * j.Y;
			}
		}
		while(ptr <= L[i]){
			cur += cnt[ptr] * ptr;
			sum -= cnt[ptr];
			ptr++;
		}
		ans += cur + sum * L[i];
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	A[0] = 0 , B[0] = MOD;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i] >> B[i];
		compress.push_back(A[i]);
		compress.push_back(B[i]);
	}
	sort(all(compress));
	compress.resize(unique(all(compress)) - compress.begin());
	m = SZ(compress) - 1;

	for(int i = 0 ; i <= n ; i++){
		A[i] = lower_bound(all(compress) , A[i]) - compress.begin();
		B[i] = lower_bound(all(compress) , B[i]) - compress.begin();
	}

	build();
	for(int i = 1 ; i <= n ; i++){
		update(A[i] , B[i] , i);
	}

	fill(cnt , cnt + MAXN , 0);
	for(int i = 1 ; i <= n ; i++){
		for(pii j : vec[i]){
			cnt[j.X] += j.Y;
		}
		vector<pii> res;
		for(pii j : vec[i]){
			if(cnt[j.X] != 0){
				res.push_back({j.X , cnt[j.X]});
				cnt[j.X] = 0;
			}
		}
		vec[i] = res;
	}

	ll l = 0 , r = MOD;
	while(r - l > 1){
		ll mid = l + r >> 1;
		calc(mid);
		if(count() >= k)	l = mid;
		else	r = mid;
	}

	calc(l + 1);
	k -= count();
	cout << k * l + solve(l + 1) << endl;
	
	return 0;
}
/*

*/