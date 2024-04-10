#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
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
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17;

struct line {
    lli m, k; // y = mx + k
    lli v (lli x) {
        return m * x + k;
    }
};
 
struct LiChao {
    line best;
    int l, r, m;
    LiChao* ch[2];
    LiChao (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        ch[0] = ch[1] = NULL;
        best.m = 0;
        best.k = 0;
    }
    void insert (line seg) {
        if (r - l == 1) {
            if (best.v(l) < seg.v(l)) {
                swap(seg, best);
            }
        } else {
            if (best.m < seg.m) swap(best, seg);
            if (seg.v(m) < best.v(m)) {
                if (!ch[0]) ch[0] = new LiChao(l, m);
                ch[0]->insert(seg);
            } else {
                swap(best, seg);
                if (!ch[1]) ch[1] = new LiChao(m, r);
                ch[1]->insert(seg);
            }
        }
    }
    lli query (lli x) {
        if (r - l == 1) return best.v(x);
        if (ch[x >= m]) return max(ch[x >= m]->query(x), best.v(x));
        return best.v(x);
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
	dp[i] = dp[j] + (x_i - x_j) * y_i - a_i
	      = (-y_i * x_j + dp[j]) + x_i * y_i - a_i
	*/
	int n;
	cin >> n;
	vector <pair<pll, lli>> v(n);
	fop (i,0,n) {
		cin >> v[i].X.X >> v[i].X.Y >> v[i].Y;
	}
	sort(all(v));
	LiChao root(0, mod);
	lli ans = 0;
	fop (i,0,n) {
		lli now = root.query(v[i].X.Y) + v[i].X.X * v[i].X.Y - v[i].Y;
		ans = max(ans, now);
		line l;
		l.m = -v[i].X.X; l.k = now;
		root.insert(l);
	}
	cout << ans << endl;
}