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

const ll MAXN = 1e6 + 10;
const ll LOG = 15;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , m , p , A[MAXN] , dp[1 << LOG];
pll ans = {-MOD , -MOD};
mt19937 rng(time(0));

pll solve(ll x){
	vector<int> vec;
	for(int i = 0 ; i < m ; i++){
		if(x & (1ll << i))	vec.push_back(i);
	}
	fill(dp , dp + (1 << LOG) , 0);
	for(int i = 0 ; i < n ; i++){
		ll cur = 0;
		for(int j = 0 ; j < SZ(vec) ; j++){
			if(A[i] & (1ll << vec[j]))	cur |= (1 << j);
		}
		dp[cur]++;
	}
	for(int i = 0 ; i < LOG ; i++){
		for(int j = 0 ; j < (1 << LOG) ; j++){
			if((j & (1 << i)) == 0)	dp[j] += dp[j ^ (1 << i)];
		}
	}
	int ans = 0 , cnt = -1;
	for(int i = 0 ; i < (1 << LOG) ; i++){
		if(dp[i] >= (n + 1) / 2 && __builtin_popcount(i) > cnt){
			cnt = __builtin_popcount(i);
			ans = i;
		}
	}
	ll res = 0;
	for(int i = 0 ; i < SZ(vec) ; i++){
		if(ans & (1 << i))	res |= (1ll << vec[i]);
	}
	return pll(cnt , res);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m >> p;
	for(int i = 0 ; i < n ; i++){
		string s; cin >> s;
		for(int j = 0 ; j < m ; j++){
			if(s[j] == '1')	A[i] |= (1ll << j);
		}
	}
	for(int i = 0 ; i < 50 ; i++){
		ans = max(ans , solve(A[rng() % n]));
	}
	for(int i = 0 ; i < m ; i++){
		if(ans.Y & (1ll << i))	cout << 1;
		else	cout << 0;
	}

    return 0;
}
/*

*/