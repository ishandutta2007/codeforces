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
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 300087, logN = 18, K = 500, C = 1 << 20;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, m;
    	cin >> n >> m;
    	vector <int> a(n), b(m), pos(n);
    	set <pii> A;
    	fop (i,0,n) {
    		cin >> a[i], a[i]--;
    		pos[a[i]] = i;
		}
		set <int> in;
    	fop (i,0,m) {
    		cin >> b[i], b[i]--;
			b[i] = pos[b[i]];
			in.insert(b[i]);
		}
    	lli way = 1;
    	fop (i,0,m) {
    		int cnt = 0;
    		if (b[i] > 0 && !in.count(b[i] - 1)) cnt++;
    		if (b[i] + 1 < n && !in.count(b[i] + 1)) cnt++;
    		in.erase(b[i]);
    		way = way * cnt % mod;
		}
		cout << way << endl;
	}
}