#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = 998244353;
const ll INF = 1e18;

bool good(ll n, ll k){
	vector< bool > was(10, 0);
	while(n){
		if(was[n % 10] == 0)
			k--;
		n /= 10;
	}
	return k >= 0;
}
ll pw[100][100];
int len(ll x){
	if(x < 10)
		return 1;
	return len(x / 10) + 1;
}
ll get(ll n, ll mask){
	ll res = 0, cnt = 0, sum = 0, pre = 0;
    int ln = len(n);
	bool good[10];
	for(int i = 0; i < 10; i++)
		if(mask & (1<<i)){
			//cerr << i << endl;
			good[i] = 1, cnt++, sum += i;
		}else
			good[i] = 0;
	//cerr << sum << " " << cnt << endl;
	for(int i = 1; i < ln; i++){
		ll cur = 0;
		for(int d = 1; d < 10; d++){
        	if(good[d]){
        		cur = (cur + pw[cnt][i - 1] * d % mod * pw[10][i - 1] % mod);
        		for(int j = 0; j < i - 1; j++)
					cur += sum * pw[10][j] % mod * pw[cnt][i - 2] % mod;
			}
		}
		cur %= mod;		
		res = (res + cur) % mod;
	}
	vector< int > v;
	while(n){
		v.pb(n % 10);
		n /= 10;
	}
	reverse(v.begin(), v.end());
    ln--;
    for(int i = 0; i < v.size(); i++){
		ln--;
		for(int j = (i == 0); j < 10; j++){
			if(good[j] && j < v[i]){
				ll cur = pw[cnt][ln + 1] * ((pre + j * pw[10][ln + 1]) % mod) % mod;
				for(int q = 0; q <= ln; q++)
					cur += sum * pw[10][q] % mod * pw[cnt][ln] % mod;
				cur %= mod;
				res = (res + cur) % mod;
			}
		}
		pre = (pre + v[i] * pw[10][ln + 1]) % mod;
		if(!good[v[i]])
			break;
	}
	return res;
}
ll solve(ll n, ll k){
	ll res = 0;
	ll dp[1024], m = 10;
	for(int i = 0; i < 1024; i++)
		dp[i] = 0;
	for(int i = 1; i < (1 << m); i++){
		int cnt = 0;
		for(int j = 0; j < m; j++)
			if(i & (1<<j))
				cnt++;
		ll x = get(n, i);
		for(int j = 0; j < i; j++)
			if((i & j) == j)
				x = (x - dp[j] + mod) % mod;
		dp[i] = x;
		if(cnt <= k){
        	res = (res + x) % mod;
        }
	}
	return res;
}
int main(){
	for(int i = 0; i < 100; i++)
		pw[i][0] = 1;
	for(int i = 0; i < 100; i++)
		for(int j = 1; j < 100; j++)
			pw[i][j] = pw[i][j - 1] * i % mod;
	ll l, r, ans, k;
	cin >> l >> r >> k;
	/*
	cerr << get(100, (1<<10) - 1);
	return 0;
	cerr << solve(100, 10);
	return 0;
	//cerr << solve(r, k);
	//return 0;
	 */
	ans = (solve(r + 1, k) - solve(l, k) + mod) % mod;
	cout << ans % mod;
	return 0;
}