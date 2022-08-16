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

const ll   N     =  3e5 + 5;
const ll   mod   =  998244353;
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
		build(v, 1, 1, n);
	}

	template<typename U>
	void build(const std::vector<U> &v, int node, int start, int end) {
		if (start == end) {
			tree[node] = e;
		} else {
			int mid = (start + end) / 2;
			build(v, 2 * node, start, mid);
			build(v, 2 * node + 1, mid + 1, end);
			tree[node] = f(tree[2 * node], tree[2 * node + 1]);
		}
	}

	template<typename U>
	void update(int idx, U val) {
		update_helper(1, 1, n, idx, val);
	}

	template<typename U>
	void update_helper(int node, int start, int end, int idx, U val) {
		if (start == end) {
			tree[node] = T(val);
		} else {
			int mid = (start + end) / 2;
			if (start <= idx and idx <= mid)
				update_helper(2 * node, start, mid, idx, val);
			else
				update_helper(2 * node + 1, mid + 1, end, idx, val);
			tree[node] = f(tree[2 * node], tree[2 * node + 1]);
		}
	}

	T query(int l, int r) {
		return query_helper(1, 1, n, l, r);
	}

	T query_helper (int node, int start, int end, int l, int r) {
		if (start > end or start > r or end < l)
			return e;
		if (l <= start and end <= r)
			return tree[node];
		int mid = (start + end) / 2;
		T p1 = query_helper(2 * node, start, mid, l, r);
		T p2 = query_helper(2 * node + 1, mid + 1, end, l, r);
		return f(p1, p2);
	}
};

struct node {
	ll mx;
	node(): mx(0) {}
	node(ll x) :mx(x) {}
};

ll n, q, t[N], l[N], r[N], x[N];

void solve() {
	cin >> n >> q;
	segment_tree<node> st(vector <int>(n + 1, 0), n, node(), [&](const node &a, const node &b){
		node c;
		c.mx = max(a.mx, b.mx);
		return c;
	});
	
	set <int> s;
	vector <ll> when(n + 1, INFi);
	for (int i = 1; i <= n; i++) s.insert(i);
	for (int i = 1; i <= q; i++) {
		cin >> t[i];
		if (t[i] == 0) {
			cin >> l[i] >> r[i] >> x[i];
			if (!x[i]) {
				while (1) {
					auto it = s.lower_bound(l[i]);
					if (it == s.end() || *it > r[i]) break;
					when[*it] = i;
					st.update(*it, i);
					s.erase(it);
				}
			}
		} else cin >> x[i];
	}
	
	for (int i = 1; i <= q; i++) {
		if (t[i] == 0 && x[i] == 1) {
			int start = l[i], ct = 0;
			while (1) {
				auto it = s.lower_bound(start);
				if (it == s.end() || *it > r[i] || ct > 1) break;
				start = *it + 1;
				ct++;
			}
			if (ct == 1) {
				auto it = *s.lower_bound(l[i]);
				when[it] = min(max(st.query(l[i], r[i]).mx, (ll)i), when[it]);
			}
		}
	}
	
	for (int i = 1; i <= q; i++) {
		if (t[i]) {
			if (s.find(x[i]) == s.end() && when[x[i]] <= i) deb1("NO")
			else if (when[x[i]] <= i) deb1("YES")
			else deb1("N/A")
		}
	}
	
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}