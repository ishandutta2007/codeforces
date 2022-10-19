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

const ll MAXN = 5e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , A[MAXN] , dp[MAXN] , L[MAXN] , seg[MAXN << 2];

void modify(int pos , int val , int id = 1 , int l = 0 , int r = n){
	if(r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = l + r >> 1;
	if(pos < mid)	modify(pos , val , lc , l , mid);
	else	modify(pos , val , rc , mid , r);
	seg[id] = max(seg[lc] , seg[rc]);
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = n){
	if(qr <= l || r <= ql)	return 0;
	if(ql <= l && r <= qr)	return seg[id];
	int mid = l + r >> 1;
	return max(get(ql , qr , lc , l , mid) , get(ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		fill(seg , seg + (n + 5) * 4 , 0);
		vector<pii> vec; 
		vector<int> stk = {-1};
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			vec.push_back({A[i] , i});
		}
		for(int i = 0 ; i < n ; i++){
			while(SZ(stk) > 1 && A[stk.back()] <= A[i])	stk.pop_back();
			L[i] = stk.back();
			stk.push_back(i);
		}
		int ans = 0;
		sort(all(vec));
		for(pii _ : vec){
			int i = _.Y;
			dp[i] = get(0 , i) + 1;
			if(i >= 1){
				dp[i] = max(dp[i] , get(0 , L[i]) + 2);
			}
			modify(i , dp[i]);
			ans = max(ans , dp[i]);
//			cout << i << sep << dp[i] << endl;
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/