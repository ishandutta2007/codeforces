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

const int mod = 1e8, x = 864197532, N = 100000, logN = 17;

int main () {
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	if (n > m) {
		swap(n, m);
		swap(s, t);
	}
	auto check = [&](string s, int n, int k) {
		fop (i,0,n) {
			if (s[i] != s[i % k]) return false;
		}
		return true;
	};
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0 and m % i == 0) {
			if (check(s, n, i) and check(t, m, i) and s.substr(0, i) == t.substr(0, i)) ans++;
		}
	}
	cout << ans << endl;
}