#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 350;

template <typename T>
struct Seg {
	int l, r, m;
	T sum, addTag;
	Seg* ch[2];
	Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
		sum = addTag = 0;
		if (r - l != 1) {
			ch[0] = new Seg <T>(l, m);
			ch[1] = new Seg <T>(m, r);
			pull();
		}
	}
	int size() {return r - l;}
	void pull() {sum = ch[0]->sum + ch[1]->sum;}
	void addValue(T v) {sum += v * size();};
	void push() {
		if (addTag) {
			if (r - l != 1) {
				ch[0]->addValue(addTag);
				ch[0]->addTag += addTag;
				ch[1]->addValue(addTag);
				ch[1]->addTag += addTag;
			}
			addTag = 0;
		}
	}
	void set(int p, T v) {
		if (r - l == 1) {
			sum = v;
		} else {
			push();
			if (p < m) {
				ch[0]->set(p,v); 
			} else {
				ch[1]->set(p,v);
			}
			pull();
		}
	}
	T query(int a, int b) {
		if (a <= l and r <= b) return sum;
		push();
		T ans = 0;
		if (a < m) ans += ch[0]->query(a,b); 
		if (m < b) ans += ch[1]->query(a,b);
		return ans;
	}
	void add(int a, int b, T v) {
		if (a >= b) return;
		if (a <= l and r <= b) {
			addValue(v);
			addTag += v;
		} else {
			push();
			if (a < m) ch[0]->add(a,b,v);
			if (m < b) ch[1]->add(a,b,v);
			pull();
		}
	}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
	vector <pii> v(q);
	fop (i,0,q) cin >> v[i].X >> v[i].Y, v[i].X--, v[i].Y--;
	auto ask = [&](int x) {
		vector <pii> aa;
		vector <int> bb[n];
		Seg <int> root(0, m);
		fop (i,0,x) {
			if (v[i].X % 2 == 0) aa.pb({v[i].X / 2, v[i].Y / 2});
			else bb[v[i].X / 2].pb(v[i].Y / 2);
		}
		sort(all(aa), [](pii a, pii b) {
			return a.X > b.X;
		});
		bool is = true;
		int now = n - 1;
		for (pii A : aa) {
			while (now >= A.X) {
				for (int i : bb[now]) {
					root.set(i, 1);
				}
				now--;
			}
			if (root.query(A.Y, m) > 0) is = false;
		}
		return is;
		/*
		X O 
		 X O
		O O
		 O X
		O O
		 O O
		*/
	};
	int l = 0, r = q + 1;
	while (r - l > 1) {
		int mid = l + r >> 1;
		if (ask(mid)) l = mid;
		else r = mid;
	}
	fop (i,0,q) cout << (i < l ? "YES\n" : "NO\n");
}