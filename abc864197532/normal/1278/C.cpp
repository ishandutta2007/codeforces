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

void solve() {
	int n;
	cin >> n;
	int a[2*n];
	int all = 0;
	fop (i,0,2*n) {
		cin >> a[i];
		if (a[i] == 1) all++;
		else all--;
	}
	if (all == 0) {
		cout << 0 << endl;
		return;
	}
	map <int,int> m1;
	int now = 0, ans = 2*n; // = 1 - 2
	m1[now] = 0;
	FOP (i,n,0) {
		if (a[i] == 1) now++;
		else now--;
		if (!m1.count(now)) m1[now] = n - i;
	}
	now = 0;
	if (m1.count(all)) ans = m1[all];
	fop (i,n,2*n) {
		if (a[i] == 1) now++;
		else now--;
		if (m1.count(all - now)) ans = min(m1[all-now] + i - n + 1, ans);
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