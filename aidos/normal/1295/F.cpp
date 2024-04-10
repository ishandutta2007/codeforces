#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = (int)998244353;
const int maxn = (int)3e5 + 100;
ll binpow(ll n, ll x) {
	if(x == 0) return 1;
	if(x & 1) return binpow(n, x-1) * n % mod;
	return binpow(n*n % mod, x / 2);
}
int l[55], r[55], n;
vector<int> pos;
ll dp[55][255];
map<pair<int, int>, int> M;
ll calc(int n, int k) {
	n += k-1;
	if(M.count(mp(n, k))) return M[mp(n, k)];
	ll res = 1;
	vector<int> a;
	for(int i = n - k + 1; i <= n; i++) {
		a.push_back(i);
	} 
	for(int i = 1; i <= k; i++) {
		int j = i;
		for(int t = 0; t < a.size(); t++) {
			int g = __gcd(j, a[t]);
			a[t]/=g;
			j/=g;
		}
	}
	for(int i = 0; i < a.size(); i++) res = (res * a[i]) % mod;
	M[mp(n, k)] = res;
	return res;
}
ll get(int x, int y) {
	if(x == n) return 1;
	if(y == pos.size()) return 0;
	ll &res = dp[x][y];
	if(res != -1) return res;
	res = 0;
	for(int j = y; j < pos.size(); j++) {
		int i = x;
		while(i < n && pos[j] >= l[i] && pos[j] <= r[i]) {
			i++;
			if(j+1 == pos.size())  res = (res + get(i, j+1)) % mod;
			else res = (res + calc(pos[j+1] - pos[j], i-x) * get(i, j+1) % mod) % mod;
		}
	}
	return res;
}
void solve(){
	ll p = 0, q = 1;
	cin >> n;
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		q = q * (r[i] - l[i] + 1) % mod;
		pos.push_back(l[i]);
		pos.push_back(r[i]);
		pos.push_back(r[i]+1);
	}
	q = binpow(q, mod-2);
	sort(pos.begin(), pos.end());
	pos.resize(unique(pos.begin(),pos.end())-pos.begin());
	reverse(l, l + n);
	reverse(r, r + n);

	for(int j = 0; j < pos.size(); j++) {
		int i = 0;
		while(i < n && pos[j] >= l[i] && pos[j] <= r[i]) {
			i++;
			if(j+1 == pos.size())  p = (p + get(i, j+1)) % mod;
			else p = (p + calc(pos[j+1] - pos[j], i) * get(i, j+1)) % mod;
			//break;
		}
		//break;
	}

	cout << p * q % mod << "\n";
}
int main () {
	solve();
 	return 0;
}