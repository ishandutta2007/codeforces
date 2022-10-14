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

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, d;
	cin >> n >> k >> d;
	int a[n + 1];
	fop (i,1,n + 1) cin >> a[i];
	sort(a + 1, a + n + 1);
	/*
	3 4 4 5 10 13
	*/
	bool dp[n + 1];
	deque <int> dq;
	dp[0] = true;
	dq.push_back(0);
	fop (i,1,n + 1) {
		while (dq.size() and a[i] - a[dq.front() + 1] > d) dq.pop_front();
		dp[i] = (dq.size() and i - dq.front() >= k);
		if (dp[i]) dq.push_back(i);
	}
	cout << (dp[n] ? "Yes\n" : "No\n");
}