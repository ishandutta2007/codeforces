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

const ll   N     =  2e6 + 5;
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

	void pushlazy(int start, int end, int node) {
		if (tree[node].lazy == 0) return;
		
		tree[node].sum += (end - start + 1) * tree[node].lazy;
		
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	template<typename U>
	void update(int l, int r, U val) {
		update_helper(1, 1, n, l, r, val);
	}

	template<typename U>
	void update_helper(int node, int start, int end, int l, int r, U val) {
		pushlazy(start, end, node);
		if (start > end || start > r || end < l)
			return;
		if (start >= l && end <= r) {
			tree[node].lazy += val;
			pushlazy(start, end, node);
		} else {
			int mid = (start + end) / 2;
			update_helper(node * 2, start, mid, l, r, val);
			update_helper(node * 2 + 1, mid + 1, end, l, r, val);
			tree[node] = f(tree[2 * node], tree[2 * node + 1]);
		}
	}

	T query(int i) {
		return query_helper(1, 1, n, i);
	}

	T query_helper (int node, int start, int end, int i) {
		pushlazy(start, end, node);
		if (start == end)
			return tree[node];
		int mid = (start + end) / 2;
		if (i <= mid) return query_helper(2 * node, start, mid, i);
		else return query_helper(2 * node + 1, mid + 1, end, i);
	}
};

struct node {
	ll sum, lazy;
	node(): sum(0), lazy(0) {}
};

ll n, q, col[N];

void solve() {
	cin >> n >> q;
	segment_tree<node> st(vector <int>(n + 1, 0), n, node(), [&](const node &a, const node &b){
		node c;
		c.sum = a.sum + b.sum;
		return c;
	});
	
	set <tuple <int, int, int>> s;
	s.insert({n, 1, 1});
	for (int i = 1; i <= q; i++) {
		string qi; cin >> qi;
		if (qi[0] == 'A') {
			int c, x; cin >> c >> x;
			col[c] += x;
		} else if (qi[0] == 'C') {
			int c, l, r; cin >> l >> r >> c;
			while (1) {
				auto it = s.lower_bound({l, 0, 0});
				if (it == s.end()) break;
				auto [ri, li, ci] = *it;
				if (li > r) break;
				s.erase(it);
				if (li < l) {
					s.insert({l - 1, li, ci});
				}
				if (ri > r) {
					s.insert({ri, r + 1, ci});
				}
				st.update(max(li, l), min(ri, r), col[ci]);
			}
			s.insert({r, l, c});
			st.update(l, r, -col[c]);
		} else {
			int x; cin >> x;
			node p = st.query(x);
			auto [ri, li, ci] = *s.lower_bound({x, 0, 0});
			deb1(col[ci] + p.sum)
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