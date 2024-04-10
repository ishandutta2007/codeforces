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
const int mod = 1e9 + 9, x = 864197532, N = 100087, logN = 18, K = 350;

lli modpow(lli a, lli b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

int main () {
	int n, s;
	cin >> n >> s; s--; 
	vector <int> a(n), cnt(n, 0);
	fop (i,0,n) cin >> a[i];
	int ans = (a[s] != 0), mx = 0, tmp = 0;
	fop (i,0,n) if (i != s) {
		if (a[i] == 0) ans++, tmp++;
		else cnt[a[i]]++;
		mx = max(mx, a[i]);
	}
	vector <int> del;
	fop (i,1,mx + 1) {
		if (cnt[i] == 0) del.pb(i);
	}
	int now = tmp;
	FOP (i,n,0) {
		if (now >= del.size() || del[now] >= i) {
			break;
		}
		if (cnt[i]) {
			while (del[now] < i && cnt[i] && now < del.size()) {
				cnt[del[now++]] = 1;
				cnt[i]--;
				ans++;
			}
		}
	}
	cout << ans << endl;
}