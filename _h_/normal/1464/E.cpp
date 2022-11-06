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

int k = 17;
const ll md = 998244353;

ll mpow(ll a, ll e){
	ll res = 1;
	for(; e; e >>= 1, a = a * a % md)
		if(e & 1) res = res * a % md;
	return res;
}

ll inv(ll x){ return mpow(x, md-2); }

void hada(vi &v, int fr, int to){
	if(fr+1 == to) return;
	int mi = (fr + to)/2;
	rep(i,fr,mi){
		int j = i + mi-fr;
		int t = v[j];
		v[j] = (v[i] - v[j]) % md;
		v[i] = (v[i] + t) % md;
	}
	hada(v, fr, mi);
	hada(v, mi, to);
}

void ihada(vi &v, int fr, int to){
	if(fr+1 == to) return;
	int mi = (fr + to)/2;
	ihada(v, fr, mi);
	ihada(v, mi, to);
	rep(i,fr,mi){
		int j = i + mi-fr;
		int t = v[j];
		v[j] = (v[i] - v[j]) % md;
		v[i] = (v[i] + t) % md;
	}
}

void invert(vi &v){
	assert(sz(v) == 1 << k);
	hada(v, 0, sz(v));
	trav(x, v) x = inv(x);
	ihada(v, 0, sz(v));
	ll mul = mpow(2, md-1 - k);
	trav(x, v) x = (x * mul) % md;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vector<vi> ut(n), in(n);
	vi deg(n);

	rep(_,0,m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		ut[u].push_back(v);
		in[v].push_back(u);
		++deg[u];
	}
	stack<int> st;
	rep(i,0,n) if(deg[i] == 0) st.push(i);

	vi val(n);

	while(!st.empty()){
		int i = st.top(); st.pop();

		vi seen(sz(ut[i])+1, false);
		trav(j, ut[i]) if(val[j] < sz(seen)) seen[val[j]] = true;

		rep(k,0,sz(seen)) if(!seen[k]){
			val[i] = k;
			break;
		}
		trav(j, in[i]) if(--deg[j] == 0) st.push(j);
	}

	vi p(1<<k);
	p[0] += n+1;
	rep(i,0,n) --p[val[i]];
	invert(p);

	ll ans = (1 - p[0]) % md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}