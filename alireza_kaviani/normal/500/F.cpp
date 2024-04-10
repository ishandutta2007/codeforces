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

const ll MAXN = 4000 + 10;
const ll MAXP = 2e4 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , p , q , dp[LOG][MAXN] , ans[MAXP];
vector<pii> vec[MAXP << 2] , Q[MAXP << 2];

void insert(int ql , int qr , int C , int H , int id = 1 , int l = 0 , int r = MAXP){
	if(qr <= l || r <= ql)	return;
	if(ql <= l && r <= qr){
		vec[id].push_back({C , H});
		return;
	}
	int mid = l + r >> 1;
	insert(ql , qr , C , H , lc , l , mid);
	insert(ql , qr , C , H , rc , mid , r);
}

void insertQ(int pos , int B , int i , int id = 1 , int l = 0 , int r = MAXP){
	if(r - l == 1){
		Q[id].push_back({B , i});
		return;
	}
	int mid = l + r >> 1;
	if(pos < mid)	insertQ(pos , B , i , lc , l , mid);
	else	insertQ(pos , B , i , rc , mid , r);
}

void solve(int h = 1 , int id = 1 , int l = 0 , int r = MAXP){
	for(int i = 0 ; i < MAXN ; i++){
		dp[h][i] = dp[h - 1][i];
	}
	for(auto &[C , H] : vec[id]){
		for(int i = MAXN - 1 ; i >= C ; i--){
			dp[h][i] = max(dp[h][i] , dp[h][i - C] + H);
		}
	}
	if(r - l == 1){
		for(auto &[B , i] : Q[id]){
			ans[i] = dp[h][B];
		}
		return;
	}
	int mid = l + r >> 1;
	solve(h + 1 , lc , l , mid);
	solve(h + 1 , rc , mid , r);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> p;
	for(int i = 1 ; i <= n ; i++){
		int c , h , t;
		cin >> c >> h >> t;
		insert(t , t + p , c , h);
	}
	cin >> q;
	for(int i = 1 ; i <= q ; i++){
		int A , B;
		cin >> A >> B;
		insertQ(A , B , i);
	}
	solve();
	for(int i = 1 ; i <= q ; i++){
		cout << ans[i] << endl;
	}

	return 0;
}
/*

*/