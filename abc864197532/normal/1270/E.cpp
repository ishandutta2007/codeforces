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

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vector <int> ans;
	cin >> n;
	int x[n], y[n];
	fop (i,0,n) {
		cin >> x[i] >> y[i];
		if ((x[i] + y[i]) & 1) ans.pb(i);
	}
	if (ans.size() > 0 and ans.size() < n) {
		cout << ans.size() << endl;
		for (int i : ans) cout << i + 1 << ' ';
		cout << endl;
		return 0;
	}
	while (true) {
		ans.clear();
		bool is = x[0] & 1, iss = y[0] & 1;
		fop (i,0,n) {
			if (is) x[i]++;
			if (iss) y[i]++;
		}
		fop (i,0,n) {
			if ((x[i] + y[i]) & 1) ans.pb(i);
		}
		if (ans.size() > 0 and ans.size() < n) {
			cout << ans.size() << endl;
			for (int i : ans) cout << i + 1 << ' ';
			cout << endl;
			break;
		}
		ans.clear();
		fop (i,0,n) {
			if (x[i] & 1) ans.pb(i);
		}
		if (ans.size() > 0 and ans.size() < n) {
			cout << ans.size() << endl;
			for (int i : ans) cout << i + 1 << ' ';
			cout << endl;
			break;
		}
		if (ans.size() == n) {
			fop (i,0,n) x[i]++, y[i]++;
		}
		fop (i,0,n) {
			x[i] /= 2, y[i] /= 2;
		}
	}
	return 0;
}