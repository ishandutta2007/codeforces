// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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

const int Mod = 1000000007;
const int N = (1e5 + 30) + 10;
const ll Log = 30;

const int Base = 101;

int pw[N], p2[N];

int mul(int a, int b){
	return (1ll * a * b) % Mod;
}


struct node {
	int h;
	bool c0;
	node *lc, *rc;
	node (){
		h = 0;
		c0 = 1;
		lc = this;
		rc = this;
	}
	void Set(int idx, node* g, int L, int R){
		if(L + 1 == R){
			h = 1;
			c0 = 0;
			return ;
		}
		int mid = (L + R) >> 1;
		if(idx < mid){
			lc = new node(); rc = g -> rc;
			lc -> Set(idx, g -> lc, L, mid);
		} else {
			lc = g -> lc; rc = new node();
			rc -> Set(idx, g -> rc, mid, R);
		}
		h = mul(pw[R - mid], lc -> h) + rc -> h;
		if(h >= Mod) h -= Mod;
		c0 = (lc -> c0) | (rc -> c0);
	}
	int Find(int idx, int L, int R){
		if(R <= idx) return -1;
		if((idx <= L) && (!c0)) return -1;
		if(L + 1 == R) return (c0 ? L : -1);
		
		int mid = (L + R) >> 1;
		int res = lc -> Find(idx, L, mid);
		if(res != -1) return res;
		return rc -> Find(idx, mid, R);
	}
	void Off(int l, int r, node* g, int L, int R){
		if(r <= L || R <= l) return ;
		if(l <= L && R <= r){
			c0 = true; h = 0;
			lc = this; rc = this;
			return ;
		}
		int mid = (L + R) >> 1;
		if(l < mid){
			lc = new node();
			lc -> Off(l, r, g -> lc, L, mid);
		} else lc = g -> lc;

		if(mid < r){
			rc = new node();
			rc -> Off(l, r, g -> rc, mid, R);
		} else rc = g -> rc;
		
		h = mul(pw[R - mid], lc -> h) + rc -> h;
		if(h >= Mod) h -= Mod;
		c0 = (lc -> c0) | (rc -> c0);
	}
	bool Less(node* b, int L, int R){
		if(h == b -> h) return false;
		if(L + 1 == R) return c0;
		int mid = (L + R) >> 1;
		if(rc -> h != b -> rc -> h)
			return rc -> Less(b -> rc, mid, R);
		return lc -> Less(b -> lc, L, mid);
	}
};
node* root[N];
int par[N], ans[N];
vector< pair<int, int> > G[N];

struct CMP {
	bool operator ()(int A, int B){
		if(root[A] -> Less(root[B], 0, N)) return true;
		if(root[B] -> Less(root[A], 0, N)) return false;
		return A < B;
	}
};
multiset<int, CMP> st;

node* Add(node* X, int idx){
	node* res = new node();
	int fn = X -> Find(idx, 0, N);
	assert(fn != -1);
	
	if(fn != idx){
		node* Y = new node();
		Y -> Off(idx, fn, X, 0, N);
		X = Y;
	}
	res -> Set(fn, X, 0, N);
	return res;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pw[0] = 1; for(int i = 1; i < N; i++) pw[i] = mul(pw[i - 1], Base);
	p2[0] = 1; for(int i = 1; i < N; i++) p2[i] = mul(p2[i - 1], 2);

	int n, m;
	cin >> n >> m;
	int u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}

	node* Inf = new node();
	Inf -> Set(N - 1, new node(), 0, N);
	for(int i = 1; i <= n; i++)
		root[i] = Inf;

	int s, t;
	cin >> s >> t;
	if(s == t) return cout << "0\n1\n1\n", 0;
	root[s] = new node();
	st.insert(s);
	
	node* tmp;
	while(!st.empty()){
		int fr = *st.begin();
		st.erase(fr);
		for(auto [adj, w] : G[fr]){
			tmp = Add(root[fr], w);
			if(tmp -> Less(root[adj], 0, N)){
				par[adj] = fr;
				ans[adj] = (ans[fr] + p2[w]) % Mod;
				st.erase(adj);
				root[adj] = tmp;
				st.insert(adj);
			}
		}
	}
	if(par[t] == 0) return cout << "-1\n", 0;
	cout << ans[t] << '\n';
	vector<int> P;
	P.pb(t);
	while(t != s){
		P.pb(t = par[t]);
	}
	cout << P.size() << '\n';
	reverse(all(P));
	for(auto x : P) cout << x << ' ';
	cout << '\n';
	return 0;
}