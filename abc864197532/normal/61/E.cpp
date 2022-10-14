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
const int mod = 998244353, x = 864197532, N = 300000, logN = 17;

template <typename T>
struct BIT {
	int n;
	vector <T> sum;
	BIT (int n) : n(n) {sum.resize(n + 1);}
	void add (int p, T a) {for (int i = p; i <= n; i += (i & -i)) sum[i] += a;}
	T query (int p) {T all = 0; for (int i = p; i > 0; i -= (i & -i)) all += sum[i]; return all;}
	int kth (T k) {
		int ans = 0;
		for (int i = 1 << __lg(n); i > 0; i >>= 1) if (ans + i <= n and sum[ans + i] < k) k -= sum[ans += i];
		return ans + 1;
	}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n), v(n);
    fop (i,0,n) cin >> a[i], v[i] = a[i];
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    fop (i,0,n) a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
    BIT <int> bit1(v.size()), bit2(v.size());
    fop (i,0,n) {
    	bit2.add(a[i], 1);
	}
	lli ans = 0;
	fop (i,0,n) {
		if (i) bit1.add(a[i - 1], 1);
		bit2.add(a[i], -1);
		ans += 1ll * (bit1.query(v.size()) - bit1.query(a[i])) * bit2.query(a[i] - 1);
	}
	cout << ans << endl;
}