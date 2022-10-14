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
	int n,m,tmp;
	cin >> n >> m;
	lli ans = 0;
	queue<int> q1;
	set <int> s1;
	fop (i,0,n) {
		cin >> tmp;
		q1.push(tmp);
		s1.insert(tmp);
	}
	int before = 0;
	fop (i,0,m) {
		cin >> tmp;
		int aa, bb = 0;
		if (!s1.count(tmp)) {
			ans++;
			before--;
			continue;
		}
		int c = 0;
		while (true) {
			aa = q1.front();
			q1.pop();
			c++;
			s1.erase(aa);
			if (aa == tmp) {
				ans += (2 * (c + before) - 1);
				break;
			}
			bb++;
		}
		before += bb;
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