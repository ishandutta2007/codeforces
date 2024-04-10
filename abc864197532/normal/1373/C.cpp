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
const int mod = 1e9 + 7, x = 864197532, N = 1000007, logN = 20, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		int pre[n + 1];
		pre[0] = 0;
		vector <int> aa(n + 1, x);
		int mn = 0;
		fop (i,0,n) {
			if (s[i] == '+') pre[i + 1] = pre[i] + 1;
			else pre[i + 1] = pre[i] - 1;
			if (pre[i + 1] < 0) aa[-pre[i + 1] - 1] = min(aa[-pre[i + 1] - 1], i + 1);
			mn = min(mn, pre[i + 1]);
		}
		FOP (i,n + 1,1) aa[i - 1] = min(aa[i - 1], aa[i]);
		/*
		-1 -2 -1 -2
		0 -1 0 -1
		2 1 2 1
		
		-1 -2 -3
		0 -1 -2
		1 0 -1
		2 1 0
		*/
		lli ans = 0;
		fop (i,0,-mn) {
			ans += aa[i];
		}
		cout << ans + n << endl;
	}
}