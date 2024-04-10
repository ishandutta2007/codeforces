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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;
const double eps = 1e-11;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	lli a[n], pre[n + 1], head[n + 1], back[n + 1];
	head[0] = 0;
	back[n] = n;
	pre[0] = 0;
	fop (i,0,n) cin >> a[i];
	fop (i,0,n) pre[i + 1] = pre[i] + a[i];
	fop (i,1,n + 1) {
		if (pre[head[i - 1]] > pre[i]) {
			head[i] = head[i - 1];
		} else {
			head[i] = i;
		}
	}
	FOP (i,n,0) {
		if (pre[back[i + 1]] > pre[i]) {
			back[i] = back[i + 1];
		} else {
			back[i] = i;
		}
	}
	/*
	0, a, b, c, n
	pre_a - pre_0 - (pre_b - pre_a) + (pre_c - pre_b) - (pre_n - pre_c)
	-pre_n + 2 * pre_a - 2 * pre_b + 2 * pre_c
	*/
	lli ans = -1ll << 60;
	int id = -1;
	fop (i,0,n + 1) {
		if (ans < pre[back[i]] * 2 + pre[head[i]] * 2 - pre[n] - pre[i] * 2) {
			ans = pre[back[i]] * 2 + pre[head[i]] * 2 - pre[n] - pre[i] * 2;
			id = i;
		}
	}
	cout << head[id] << ' ' << id << ' ' << back[id] << endl; 
}