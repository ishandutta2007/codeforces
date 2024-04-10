#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 5e3 + 10;
const ll INF = (ll) 1e15 + 1;

ll a[MAXN];


vector<ll> p[MAXN];

ll ispower(ll n, ll po){
	ll up, low = 1;
	if(po == 2) up = 1414213570ll;
	if(po == 3) up = 1259940ll;
	if(po == 4) up = 37620ll;
	ll mid, x;
	while(up > low + 1ll){
		mid = (up+low) / 2ll;
		x = 1ll;
		for(int i = 0;i < po;i++) x *= mid;
		if(x <= n) low = mid;
		else up = mid;
	}
	return low;
}

ll gcd (ll n1,ll n2) {
    return (n2 == 0ll) ? n1 : gcd (n2, n1 % n2);
}

map<ll, ll> ma;

int main(){
    
    ll n;
    cin >> n;
    ll ans = 1,cnt;
    for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	ll p2,p3,p4,g, f;
	for(int i = 0;i<n;i++){
		if(a[i] == 1) continue;
		p2 = ispower(a[i], 2ll);
		p3 = ispower(a[i], 3ll);
		p4 = ispower(a[i], 4ll);
		/*debug(a[i]);
		debug(p2);
		debug(p3);
		debug(p4);*/
		
		if(p4*p4*p4*p4 == a[i]){
			//debug(a[i]);
			//cout << 4;
			for(int j =0;j<4;j++)p[i].pb(p4);
			continue;
		}
		
		if(p3*p3*p3 == a[i]){
			//debug(a[i]);
			//cout << 3;
			for(int j =0;j<3;j++)p[i].pb(p3);
			continue;
		}
		//debug(a[i]%p2);
		if(p2*p2 == a[i]){
			//debug(a[i]);
			//cout << 2;
			//debug(n);
			for(int j =0;j<2;j++)p[i].pb(p2);
			continue;
		}
		//debug(n);
		f = 0;
		for(int j =0;j<n;j++){
			g = gcd(a[i],a[j]);
			if((g != 1) and (g != a[i]) and (f==0)){
				p[i].pb(g);
				p[i].pb(a[i]/g);
				f = 1;
			}
		}
		cnt = 1;
		if(f == 0){
			for(int j = i + 1; j < n; j++){
				if(a[i] == a[j] ){
					cnt++;
					a[j] = 1;
				}
			}
			//debug(a[i]);
			//debug(cnt);
			ans *= ((cnt + 1)*(cnt + 1));
		
			ans %= MOD;
		}
		
	}
	for(int i =0;i<n;i++){
		//debug(i);
		for(int j =0;j<p[i].size();j++){
			//debug(di);
			//debug(di);
			ma[p[i][j]] ++;
		}
	}
	//debug(ans);
	for(map<ll,ll>::const_iterator it = ma.begin();it!=ma.end();it++){
		//debug(pri.F);
		//debug(pri.S);
		ans = ans * ((ll)((it->S) + 1ll));
		ans %= MOD;
	}
	cout << ans % MOD << endl;
	fflush(stdout);
	return 0;
}