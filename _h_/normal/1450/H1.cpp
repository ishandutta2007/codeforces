#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll md = 998244353;

ll mpow(ll a, ll e){
	ll res = 1;
	for(; e; e >>= 1, a = a * a % md){
		if(e & 1) res = res * a % md;
	}
	return res;
}

ll inv(ll x){
	return mpow(x, md-2);
}

const int mx = 2e5+10;

ll fs[mx];
ll ifs[mx];

void init(){
	fs[0] = 1;
	rep(i,1,mx) fs[i] = fs[i-1] * i % md;
	rep(i,0,mx) ifs[i] = inv(fs[i]);
}

ll bin(int n, int k){
	return fs[n] * ifs[k] % md * ifs[n-k] % md;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	init();

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	int dif = 0;
	int que = count(all(s), '?');
	rep(i,0,n) if(s[i] != '?'){
		dif += ((s[i] == 'b') == (i%2)) ? 1 : -1;
	}
	ll sum = 0;
	ll ways = 0;
	rep(i,0,que+1){
		int s = i - (que-i);
		if( (dif + s) % 4 == 0){
			ll cur = bin(que, i);
			sum = (sum + cur * abs(dif+s)/4) % md;
			ways = (ways + cur)%md;
		}
	}
	ll ans = sum * inv(ways);
	ans %= md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}