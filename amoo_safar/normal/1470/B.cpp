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

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll p[N];

ll a[N];
map<ll, ll> mp, mp1;

ll Get(ll x){
	if(x == 1) return 1;
	if(x % (p[x] * p[x]) == 0) return Get(x / (p[x] * p[x]));
	return p[x] * Get(x / p[x]);
}

ll Odd(ll x){
	int cnt = 0;
	while(x > 1){
		cnt ^= 1;
		x /= p[x];
	}
	return cnt;
}

int Main(){
	mp.clear();
	mp1.clear();
	ll n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = Get(a[i]);
		// cerr << "! " << a[i] << '\n';
		mp[a[i]] ++;
	}
	ll ans0 = 0;
	for(auto x : mp) ans0 = max(ans0, x.S);
	// debug(ans0);
	for(auto x : mp){
		if(x.S % 2 == 1)
			mp1[x.F] += x.S;
		else
			mp1[1] += x.S;
	}
	ll ans1 = 0;
	for(auto x : mp1) ans1 = max(ans1, x.S);
	ll q;
	cin >> q;
	ll w;
	for(int i = 1; i <= q; i++){
		cin >> w;
		cout << (w ? ans1 : ans0) << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 2; i < N; i++){
		if(p[i]) continue;
		for(int j = i; j < N; j += i)
			p[j] = i;
	}
	debug(Get(24));
	int T = 1;
	cin >> T; 
	while(T --) Main();
	return 0;
}