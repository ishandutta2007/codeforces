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
const int mod = 998244353, x = 864197532, N = 500001, logN = 17, K = 350;

struct BIT {
	vector <int> bit;
	int n;
	BIT (int _n) : n(_n) {
		bit.resize(n + 1, 0);
	}
	void add(int p, int v) {
		for (int i = p; i <= n; i += i & (-i)) {
			bit[i] += v;
		}
	}
	int query(int p) {
		int ans = 0;
		for (int i = p; i > 0; i -= i & (-i)) {
			ans += bit[i];
		}
		return ans;
	} 
};

lli modpow(lli a, lli b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt = 0, cnt2 = 0;
    cin >> n;
    vector <int> a(n), pos(n, -1), pre(n + 1, 0);
    fop (i,0,n) {
    	cin >> a[i];
    	if (a[i] != -1) pos[--a[i]] = i;
		pre[i + 1] = pre[i] + (a[i] == -1);
	}
	cnt = pre[n];
    lli ans = 0, base = 1;
    fop (i,1,cnt) base = base * i % mod;
    // number v.s. -1
    FOP (i,n,0) {
    	if (pos[i] == -1) {
    		cnt--;
    		cnt2++;
		} else {
			ans = (ans + (1ll * (pre[n] - pre[pos[i]]) * base % mod * cnt % mod) + (1ll * cnt2 * pre[pos[i]] % mod * base % mod)) % mod;
		}
	}
	BIT bit(n + 10);
	// -1 v.s. -1
	if (pre[n] > 1) {
		lli cur = (1ll * pre[n] * (pre[n] - 1) / 2) % mod;
		cur = cur * cur % mod;
		fop (i,1,pre[n] - 1) {
			cur = cur * i % mod;
		}
		ans = (ans + cur) % mod;
	}
	fop (i,1,pre[n] + 1) ans = ans * modpow(i, mod - 2) % mod;
    // number v.s. number
    fop (i,0,n) {
    	if (a[i] != -1) {
    		ans = (ans + bit.query(n + 10) - bit.query(a[i] + 1)) % mod;
    		bit.add(a[i] + 1, 1);
		}
	}
	cout << ans << endl; 
}