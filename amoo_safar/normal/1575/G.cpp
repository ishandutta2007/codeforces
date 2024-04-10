// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld pi = acos(-1);
const ll Mod = 1000000007LL;
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N], u[N], c[N], cnt[N], c2[N];
vector<int> D[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 1; i < N; i++)
		for(int j = i; j < N; j += i)
			D[j].pb(i);
	int mx = 0;
	for(int i = 1; i < N; i++){
		for(auto x : D[i])
			if(x < i)
				u[i] -= u[x];
		
		if(i == 1) u[i] = 1;
		mx = max(mx, (int) D[i].size());
	}
	// debug(mx);
	for(int i = 1; i < N; i++)
		for(auto x : D[i])
			c[i] += x * u[i / x];
	// debug(c[N - 1]);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int g = 1; g <= n; g++){
		// if(g != 1) continue;
		// debug(c[g]);
		for(int i = g; i <= n; i += g)
			for(auto x : D[a[i]])
				cnt[x] ++;
		for(int i = g; i <= n; i += g){
			for(auto x : D[a[i]]){
				c2[x] += cnt[x] * c[g];
				c2[x] %= Mod;
			}
		}
		for(int i = g; i <= n; i += g)
			for(auto x : D[a[i]])
				cnt[x] --;
	}
	// for(int i = 0; i <= 6; i++) debug(c2[i]);
	// ll res = 0;
	// for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
	// 	res += __gcd(a[i], a[j]);
	// debug(res);
	ll ans = 0;
	for(int i = N - 1; i >= 1; i--){
		for(auto x : D[i]){
			if(x < i)
				(c2[x] -= c2[i]) %= Mod;
		}
		c2[i] %= Mod;
		ans += (c2[i] * i);
		ans %= Mod;
	}
	ans += Mod;
	cout << ans % Mod << '\n';
	return 0;
}