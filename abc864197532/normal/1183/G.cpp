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
const int mod = 1e9 + 7, X = 864197532, N = 100000, logN = 18, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, tmp, f;
		cin >> n;
		vector <pii> cnt(n, {0, 0});
		fop (i,0,n) cin >> tmp >> f, cnt[tmp - 1].X++, cnt[tmp - 1].Y += f;
		vector <int> pre[n + 1];
		fop (i,0,n) pre[cnt[i].X].pb(cnt[i].Y);
		priority_queue <int> pq;
		int ans1 = 0, ans2 = 0;
		FOP (i,n + 1,0) if (pq.size() || pre[i].size()) {
			for (int j : pre[i]) pq.push(j);
			ans1 += i;
			ans2 += min(pq.top(), i); pq.pop();
		}
		cout << ans1 << ' ' << ans2 << endl;
	}
}