#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(12);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  6e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, tin[N], tout[N], t, ct, ans;
vector <int> g1[N], g2[N];
set <int> s;

struct NODE{
	ll ans;
	NODE(): ans(0) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.ans = a.ans + b.ans;
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE();
		tree[node].ans = 0;
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, ll val){
	if(start == end){
		tree[node].ans += val;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE();
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

void add(int x) {
	update(1, 1, 2 * n, tin[x], x);
	update(1, 1, 2 * n, tout[x], -x);
}

void rem(int x) {
	update(1, 1, 2 * n, tin[x], -x);
	update(1, 1, 2 * n, tout[x], x);
}

void dfs1(int u) {
	int anc = 0;
	if (query(1, 1, 2 * n, 1, tin[u] - 1).ans) {
		anc = query(1, 1, 2 * n, 1, tin[u] - 1).ans;
		s.erase(anc);
		rem(anc);
		s.insert(u);
		add(u);
	} else if (query(1, 1, 2 * n, tin[u] + 1, tout[u] - 1).ans == 0) {
		ct++;
		s.insert(u);
		add(u);
	}
	// deb2(u, query(1, 1, 2 * n, 1, tin[u]).ans)
	// deb1(u)
	// debv(s)
	ans = max(ans, ct);
	for (auto v : g1[u]) {
		dfs1(v);
	}
	if (anc) {
		s.insert(anc);
		add(anc);
		ct++;
	}
	if (s.find(u) != s.end()) {
		s.erase(u);
		rem(u);
		ct--;
	}
}

void dfs2(int u) {
	tin[u] = t++;
	for (auto v : g2[u]) {
		dfs2(v);
	}
	tout[u] = t++;
}

void reset() {
	for (int i = 1; i <= n; i++) {
		g1[i].clear();
		g2[i].clear();
	}
	t = 1;
	s.clear();
	ct = 0;
	ans = 0;
	build(1, 1, 2 * n);
}

void solve() {
	cin >> n;
	reset();
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		g1[x].pb(i);
	}
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		g2[x].pb(i);
	}
	dfs2(1);
	dfs1(1);
	deb1(ans);
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}