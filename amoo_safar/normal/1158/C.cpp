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

ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 5e5 + 10;
const ll INF = (ll) LONG_LONG_MAX / 100;
const ld EPS = (ld) 1e-8;
const ll P = 104107;

ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

ll a[MAXN], p[MAXN], mk[MAXN];
vector<ll> G[MAXN], topol;
vector<pll> E;
stack<ll> st;

void add(ll u, ll v){
	G[u].pb(v);
	E.pb({u, v});
	//debug(u); debug(v);
}

void DFS(ll u){
	mk[u] = 1;
	
	for(auto adj : G[u]){
		if(mk[adj] == 0) DFS(adj);
	}
	topol.pb(u);
}

int MAIN(){
	E.clear();
	ll n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
		if(a[i] == -1) a[i] = i + 1;
	}
	while(st.size()){
		st.pop();
	}
	st.push(n + 1);
	for(int i = n; i > 0; i--){
		while(st.top() != a[i]){
			add(i, st.top());
			if(st.size() == 1){
				add(1, 2);
				add(2, 1);
				break;	
			}
			st.pop();
		}
		add(a[i], i);
		st.push(i);
	}
	topol.pb(0);
	for(int i = 1; i <= n; i++) if(mk[i] == 0) DFS(i);
	
//	for(auto x : topol) cerr << x << ' ';
//	cerr << '\n';
	for(int i = 1; i<=n;i++){
		p[topol[i]] = i;
	//	debug(i);
	}
	topol.clear();
	for(int i = 0; i<=n+1; i++){
		mk[i] = 0;
		G[i].clear();
	}
	p[n + 1] = n + 1;
	for(auto e : E){
		if(p[e.F] < p[e.S]){
			//cerr << e.F << ' ' << e.S << '\n';
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 1; i<=n;i++) printf("%lld ", p[i]);
	printf("\n");
	
}

int main(){
	ios::sync_with_stdio(0); //cin.tie(0); cout.tie(0);
	ll t;
	scanf("%lld", &t);
	while(t--) MAIN();
	return 0;
}