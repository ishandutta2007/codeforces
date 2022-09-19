#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 10883;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) (LONG_LONG_MAX - 3ll) / 2ll;
const ld EPS = (ld) 1e-8;
//const ll P = 104107;

ll mul(ll a, ll b){
	return ((a % MOD) * (b % MOD)) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

ll mn[MAXN];
ll mx[MAXN];
ll psmx[MAXN];
ll psmn[MAXN];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie();
	fill(mn, mn + MAXN, INF);
	fill(mx, mx + MAXN, -1);
	ll n, x;
	cin >> n >> x;
	ll v;
	for(int i = 0; i < n; i++){
		cin >> v;
		mn[v] = min(mn[v], (ll) i);
		mx[v] = i;
	}
	
	psmx[0] = -1;
	for(int i = 1; i <= x; i++){
		if(mx[i] == -1){
			psmx[i] = psmx[i - 1];
		} else {
			if(mn[i] <= psmx[i - 1]) psmx[i] = INF + 2;
			else psmx[i] = mx[i];
		}
	}
	
	psmn[x + 1] = INF + 100;
	for(int i = x; i> 0; i--){
		if(mx[i] == -1){
			psmn[i] = psmn[i + 1];
		} else {
			if(psmn[i + 1] <= mx[i]) psmn[i] = -2;
			else psmn[i] = mn[i];
		}
	}
	
	/*
	for(int i = 0; i<=x;i++) cerr << psmx[i] << " ";
	cerr << '\n';
	for(int i = 0; i<=x;i++) cerr << psmn[i] << " ";
	cerr << '\n';
	*/
	
	ll ans = 0;
	ll p1 = 1;
	for(int i = 0; i <= x; i++){
		//cerr << p1 << '\n';
		if(psmx[i] == INF + 2) break;
		p1 = max(p1, i + 1ll);
		while(psmn[p1] < psmx[i]) p1 ++;
		if(p1 == i + 1) ans += (x - i);
		else ans += (x - (p1 - 1) + 1);
	}
	cout << ans;
	return 0;
}