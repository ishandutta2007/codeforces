#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 200087, logN = 17;

template <typename T>
struct Seg {
	int l, r, m;
	T sum, addTag;
	Seg* ch[2];
	Seg (int l, int r, vector <int> &input): l(l), r(r), m(l + r >> 1) {
		sum = addTag = 0;
		if (r - l != 1) {
			ch[0] = new Seg <T>(l, m, input);
			ch[1] = new Seg <T>(m, r, input);
			pull();
		} else {
		    sum = input[l];
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
		T ans = -1 << 30;
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

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector <vector <int>> animal(n, vector <int>(m)), precalc(n, vector <int> (m + 1, 0));
	fop (i,0,n) {
		fop (j,0,m) {
			cin >> animal[i][j];
			precalc[i][j + 1] = precalc[i][j] + animal[i][j];
		}
	}
	vector <int> dp(m - k + 1, 0), pre(m - k + 1, 0);
	fop (i,0,m - k + 1) {
		fop (j,0,min(n, 2)) {
			dp[i] += precalc[j][i + k] - precalc[j][i]; 
		}
	}
	fop (i,1,n) {
	    Seg <int> root(0, m - k + 1, dp);
	    fop (j,0,k) root.add(0, j + 1, -animal[i][j]);
		fop (j,0,m - k + 1) {
			pre[j] = root.query(0, m) + precalc[i][j + k] - precalc[i][j] + (i + 1 < n ? precalc[i + 1][j + k] - precalc[i + 1][j] : 0);
	        root.add(max(0, j - k + 1), min(j + 1, m - k + 1), animal[i][j]);
	        root.add(j + 1, min(j + k + 1, m - k + 1), -animal[i][j + k]);
	    }
	    swap(dp, pre);
	    pre.assign(m - k + 1, 0);
	}
	cout << *max_element(all(dp)) << endl;
}