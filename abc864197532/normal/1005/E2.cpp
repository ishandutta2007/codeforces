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
const int mod = 1e9 + 7, X = 864197532, N = 300000, logN = 18, K = 350;

template <typename T>
struct Seg {
	int l, r, m;
	T sum;
	Seg* ch[2];
	Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
		sum = 0;
		if (r - l != 1) {
			ch[0] = new Seg <T>(l, m);
			ch[1] = new Seg <T>(m, r);
			pull();
		}
	}
	void pull() {sum = ch[0]->sum + ch[1]->sum;}
	void add(int p, T v) {
		if (r - l == 1) {
			sum += v;
		} else {
			if (p < m) {
				ch[0]->add(p,v); 
			} else {
				ch[1]->add(p,v);
			}
			pull();
		}
	}
	T query(int a, int b) {
		if (a <= l and r <= b) return sum;
		T ans = 0;
		if (a < m) ans += ch[0]->query(a,b); 
		if (m < b) ans += ch[1]->query(a,b);
		return ans;
	}
};

lli solve(vector <int> a, int m) {
  int n = a.size();
  int pre = 0;
  map <int, int> m1;
  lli ans = 0;
  Seg <lli> root(-N, N);
  root.add(pre, 1);
  fop (i,0,n) {
    if (a[i] >= m) pre++;
    else pre--;
    ans += root.query(-N, pre);
    root.add(pre, 1);
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> a(n);
  fop (i,0,n) cin >> a[i];
  cout << solve(a, m) - solve(a, m + 1) << endl;
}