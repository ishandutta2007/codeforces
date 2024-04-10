#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200087, logN = 18, K = 350;

vector <int> v, pos;

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
	void pull() {sum = max(ch[0]->sum, ch[1]->sum);}
	void addValue(T v) {sum += v;};
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
		T ans = -1ll << 30;
		if (a < m) ans = max(ans, ch[0]->query(a,b)); 
		if (m < b) ans = max(ans, ch[1]->query(a,b));
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

Seg <int> root(0, N);

int solve(int l, int r) {
	if (l >= r) return 0;
	int mx = root.query(l, r);
	int ans = 0, m = pos[mx];
	if (m - l < r - m) {
		fop (i,l,m) {
			int k = pos[mx - v[i]];
			if (m < k && k < r) ans++;
		}
	} else {
		fop (i,m + 1,r) {
			int k = pos[mx - v[i]];
			if (l <= k && k < m) ans++;
		}
	}
	ans += solve(l, m);
	ans += solve(m + 1, r);
	return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    pos.assign(n + 1, -1);
    v.assign(n, -1);
    fop (i,0,n) cin >> v[i], pos[v[i]] = i, root.set(i, v[i]);
    cout << solve(0, n) << endl;
}