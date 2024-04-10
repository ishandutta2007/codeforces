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

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , h[MAXN] , val[MAXN];
ll dp[MAXN] , seg[MAXN << 2];
vector<int> vec;

void modify(int x , ll val , int id = 1 , int l = 0 , int r = n + 1){
	if(r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = l + r >> 1;
	if(x < mid)	modify(x , val , lc , l , mid);
	else	modify(x , val , rc , mid , r);
	seg[id] = max(seg[lc] , seg[rc]);
}

ll get(int ql , int qr , int id = 1 , int l = 0 , int r = n + 1){
	if(qr <= l || r <= ql)	return -INF;
	if(ql <= l && r <= qr)	return seg[id];
	int mid = l + r >> 1;
	return max(get(ql , qr , lc , l , mid) , get(ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> h[i];
	}
	vec.push_back(0);
	for(int i = 1 ; i <= n ; i++){
		cin >> val[i];
		while(h[i] <= h[vec.back()])	vec.pop_back();
		dp[i] = val[i] + get(vec.back() , i);
		if(vec.back())	dp[i] = max(dp[i] , dp[vec.back()]);
		modify(i , dp[i]);
		//cout << i << sep << dp[i] << endl;
		vec.push_back(i);
	}
	cout << dp[n] << endl;

    return 0;
}
/*

*/