#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>


int main () {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (abs(b + d - a - c) > 1) {
		cout << "NO" << endl;
		return 0;
	}
	if (c < d) {
		if (a == 0 and b == 0) {
			cout << "YES" << endl;
			fop (i,0,c) cout << "3 2 ";
			cout << 3 << endl;
			return 0;
		} else {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (b < a) {
		if (c == 0 and d == 0) {
			cout << "YES" << endl;
			fop (i,0,b) cout << "0 1 ";
			cout << 0 << endl;
			return 0;
		} else {
			cout << "NO" << endl;
			return 0;
		}
	}
	vector <int> ans;
	if (b + d > a + c) {
		while (d) {
			d--;
			c--;
			ans.pb(3);
			ans.pb(2);
		} while (c) {
			b--;
			c--;
			ans.pb(1);
			ans.pb(2);
		} while (a) {
			b--;
			a--;
			ans.pb(1);
			ans.pb(0);
		}
		ans.pb(1);
	} else {
		while (a) {
			a--;
			b--;
			ans.pb(0);
			ans.pb(1);
		} while (b) {
			c--;
			b--;
			ans.pb(2);
			ans.pb(1);
		} while (d) {
			c--;
			d--;
			ans.pb(2);
			ans.pb(3);
		}
		if (c) ans.pb(2);
	}
	cout << "YES" << endl;
	fop (i,0,ans.size()) cout << ans[i] << " \n"[i == ans.size() - 1];
	return 0;
}