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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500000, logN = 17, K = 350;

struct Seg {
	int l, r, m, sz;
	lli sum;
	Seg* ch[2];
	Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
		ch[0] = ch[1] = NULL;
		sz = sum = 0;
	}
	void pull() {
		sum = (ch[0] ? ch[0]->sum : 0) + (ch[1] ? ch[1]->sum : 0);
		sz = (ch[0] ? ch[0]->sz : 0) + (ch[1] ? ch[1]->sz : 0);
	}
	void add(int p, int v) {
		if (r - l == 1) sz += v, sum += l * v;
		else {
			if (p < m) {
				if (!ch[0]) ch[0] = new Seg(l, m);
				ch[0]->add(p, v);
			} else {
				if (!ch[1]) ch[1] = new Seg(m, r);
				ch[1]->add(p, v);
			}
			pull();
		}
	}
	lli query(int k) {
		if (k <= 0) return 0;
		if (k >= sz) return sum;
		if (ch[1] && ch[1]->sz > k) {
			return ch[1]->query(k);
		} else if (ch[0]) {
			return (ch[1] ? ch[1]->sum : 0) + ch[0]->query(k - (ch[1] ? ch[1]->sz : 0));
		}
		return 0;
	}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
    2(small) ...... 1
    all 2 -> (all) * 2 - v[0];
	1 1 -> (all) * 2 - v[0];
	2 1 -> (all) * 2 - v[0] - v[1]; 
	3 1 -> 
	1 5 6   4 7
	4 7 6 5 1
	1 5 6   4 5
	4 6 5 5 1
	8 6 4   1 9
	1 9 8 6 4
	if ligthning number is k
	ans = all + sum(b[0] - b[k - 1])
	*/
	int q, x, d;
	set <int> lig;
	lli all = 0;
	cin >> q;
	Seg root(0, 1 << 30);
	while (q--) {
		cin >> x >> d;
		if (d > 0) {
			all += d;
			if (x) {
				if (lig.size()) {
					int k = *lig.begin();
					lig.insert(d);
					if (d < k) {
						root.add(k, 1);
					} else {
						root.add(d, 1);
					}
				} else {
					lig.insert(d);
				}
			} else {
				root.add(d, 1);
			}
		} else {
			d = -d;
			all -= d;
			if (x) {
				lig.erase(d);
				if (lig.size()) {
					int k = *lig.begin();
					if (d < k) {
						root.add(k, -1);
					} else {
						root.add(d, -1);
					}
				}
			} else {
				root.add(d, -1);
			}
		}
		cout << all + root.query(lig.size()) << endl;
	}
}