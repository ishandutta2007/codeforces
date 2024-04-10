#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

void solve() {
	int n,m;
	cin >> n >> m;
	lli ans = 1ll * n * (n + 1) / 2;
	if (n >= m * 2) {
		int k = (n - m) / (m + 1), r = (n - m) % (m + 1);
		ans -= (1ll * (k + 1) * (k + 2) / 2 * r);
		ans -= (1ll * k * (k + 1) / 2 * (m + 1 - r));
	} else {
		ans -= (n - m);
	}
	cout << ans << endl; 
}



int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}