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

void solve () {
	int n;
	cin >> n;
	int a[n];
	lli summ = 0, xorr = 0;
	fop (i,0,n) {
		cin >> a[i];
		summ += a[i];
		xorr ^= a[i];
	}
	vector <lli> ans;
	if (xorr != 0) {
		ans.pb(xorr);
		summ += xorr;
		xorr = 0;
	}
	if (summ != 0) ans.pb(summ);
	cout << ans.size() << endl;
	fop (i,0,ans.size()) cout << ans[i] << ' ';
	cout << endl;
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