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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <lli> a(n), pre(n + 1, 0);
    fop (i,0,n) cin >> a[i];
    sort(all(a));
    FOP (i,n,0) a[i] -= a[0];
    vector <int> cnt(N, 0);
    fop (i,0,n) cnt[a[i]]++;
    if (cnt[0] == n) {
    	cout << 0 << endl;
    	return 0;
	}
	lli ans = 1, tmp = 0;
	FOP (i,N,1) if (cnt[i]) {
		if (tmp + cnt[i] > k) {
			ans++;
			tmp = 0;
		}
		tmp += cnt[i];
		cnt[i - 1] += cnt[i];
	}
	cout << ans << endl;
}