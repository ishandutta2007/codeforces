#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 25) - 1;
const int maxn = (int)2e6+100;
const int mod = (int) 1e9 + 7;
const ll val = 1e13;
using namespace std;
int dp[1<<8][1<<8];
ll a[10];
int n;
int p[maxn];
vector<ll>pr;
ll dp2[1<<8];
ll get2(int mask) {
	ll &res = dp2[mask];
	if(res!=-1) return res;
	res = 1;
	for(int i = 0; i < n; i++) {
		if(mask&(1<<i)) {
			if(val/a[i]<res) {
				res = 0;
			}
			res *= a[i];
		}
	}
	return res;
}
map<ll, int> M;

set<ll> primes;
int PR(ll x) {
	if(x < maxn) return !p[x];
	return primes.count(x);
}
int get3(ll x) {
	if(x == 1) return 0;
	if(M.count(x)) return M[x];
	ll y = x;
	int i = 0;
	int res = 0;
	while(pr[i] * pr[i] * pr[i] <= y) {
		while(y % pr[i] == 0) {
			y/=pr[i];
			res++;
		}
		i++;
	}
	if(y == 1) return M[x] = res;
	if(PR(y)) return M[x] = res + 1;
	return M[x] = res + 2;
}
void F(ll x) {
	for(int i = 0; pr[i] * pr[i] <= x; i++) {
		while(x % pr[i] == 0) {
			x /= pr[i];
		}
	}
	if(x >= maxn) primes.insert(x); 
}
int get(int m1, int m2) {
	if(m1 == (1<<n)-1) {
		return min(__builtin_popcount(m2),2) - 1;
	}
	int &res = dp[m1][m2];
	if(res!=-1) return res;
	res = inf;
	for(int h = 0; h < (1<<n); h++) {
		if((h&m2)!=h) continue;
		ll t = get2(h);
		if(t == 0) continue;
		for(int k = 0; k < n; k++) {
			if(!(m1 & (1<<k))) {
				if(a[k] % t == 0){
					res = min(res, get(m1|(1<<k), m2^h^(1<<k)) + 1 + get3(a[k]/t));
				}
			}
		}
	}
	for(int k = 0; k < n; k++) {
		if(m1&(1<<k)) continue;
		if(PR(a[k])) {
			res = min(res, get(m1|(1<<k), m2|(1<<k)) + 1);
		}
	}
	return res;
}
void solve(){
	memset(dp, -1, sizeof dp);
	memset(dp2, -1,sizeof dp2);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(int i = 2; i < maxn; i++) {
		if(!p[i]) {
			for(int j = i * 2; j < maxn; j += i) {
				p[j] = 1;
			}
			pr.pb(i);
		}
	}
	for(int i = 0; i < n; i++) {
		F(a[i]);
	}
	cout << get(0, 0) << "\n";
}
int main () {
    int t=1;
   	//scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}