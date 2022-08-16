#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

template<typename T, typename F = std::function<T(const T&, const T&)>>
struct segment_tree {
	int n;
	std::vector<T> tree;
	T e;
	F f;

	segment_tree() : n(), e(), f() {}

	template<typename U>
	segment_tree(const std::vector<U> &v, int n, T e, F &&f): n(n), tree(4 * n), e(e), f(f) {
		build(v, 1, 0, n - 1);
	}

	template<typename U>
	void build(const std::vector<U> &v, int node, int start, int end) {
		if (start == end) {
			tree[node] = T(v[start]);
		} else {
			int mid = (start + end) / 2;
			build(v, 2 * node, start, mid);
			build(v, 2 * node + 1, mid + 1, end);
			tree[node] = f(tree[2 * node], tree[2 * node + 1]);
		}
	}

	template<typename U>
	void update(int idx, U val) {
		update_helper(1, 0, n - 1, idx, val);
	}

	template<typename U>
	void update_helper(int node, int start, int end, int idx, U val) {
		if (start == end) {
			tree[node].ans += val;
		} else {
			int mid = (start + end) / 2;
			if (start <= idx and idx <= mid)
				update_helper(2 * node, start, mid, idx, val);
			else
				update_helper(2 * node + 1, mid + 1, end, idx, val);
			tree[node] = f(tree[2 * node], tree[2 * node + 1]);
		}
	}

	T query(int x) {
		return query_helper(1, 0, n - 1, x);
	}

	T query_helper (int node, int start, int end, int x) {
		if (start > end)
			return e;
		if (start == end)
			return start;
		int mid = (start + end) / 2;
		if (tree[2 * node].ans >= x) {
			return query_helper(2 * node, start, mid, x);
		} else {
			return query_helper(2 * node + 1, mid + 1, end, x);
		}
	}
};

struct node {
	ll ans;
	node(): ans(-1) {}
	node(ll v): ans(v) {}
};

ll n, m, x[N], t[N], ct[N], val[N], ans[N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> t[i];
	}
	
	vector <int> ind(n), v;
	iota (all(ind), 0);
	sort (all(ind), [&](int i, int j){
		return x[i] < x[j];
	});
	
	for (int i = 0; i < n; i++) {
		v.pb(x[ind[i]] + t[ind[i]]);
		val[i] = t[ind[i]];
	}
	
	segment_tree<node> st(v, n, node(), [&](const node &a, const node &b){
		node c;
		c.ans = max(a.ans, b.ans);
		return c;
	});
	
	multiset <pair <int, int>> s;
	for (int i = 1; i <= m; i++) {
		int p, b; cin >> p >> b;
		if (st.tree[1].ans < p) {
			s.insert({p, b});
		} else {
			int idx = st.query(p).ans;
			if (x[ind[idx]] > p) {
				s.insert({p, b});
				continue;
			}
			st.update(idx, b);
			ct[idx]++;
			val[idx] += b;
			while (s.lower_bound({x[ind[idx]], 0}) != s.end()) {
				auto [p, b] = *s.lower_bound({x[ind[idx]], 0});
				if (p > val[idx] + x[ind[idx]]) break;
				st.update(idx, b);
				ct[idx]++;
				val[idx] += b;
				s.erase(s.find({p, b}));
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		ans[ind[i]] = ct[i];
		t[ind[i]] = val[i];
	}
	for (int i = 0; i < n; i++) deb2(ans[i], t[i])
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}