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
#define pil pair<int,lli> 

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n], now[n];
	lli ans = 0;
	map <pii, int> m1;
	fop (i,0,n) {
		cin >> a[i];
		now[i] = 0;
		ans += a[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int t1,t2,t3;
		cin >> t1 >> t2 >> t3;
		t1--, t3--;
		if (m1.count({t1,t2})) {
			if (t3 == -1) {
				int aa = m1[{t1,t2}];
				m1.erase({t1,t2});
				now[aa]--;
				if (now[aa] < a[aa]) ans++;
			} else {
				int aa = m1[{t1,t2}];
				m1[{t1,t2}] = t3;
				if (aa != t3) {
					now[aa]--;
					now[t3]++;
					if (now[aa] < a[aa]) ans++;
					if (now[t3] <= a[t3]) ans--;
				}
			}
		} else {
			if (t3 != -1) {
				m1[{t1,t2}] = t3;
				now[t3]++;
				if (now[t3] <= a[t3]) ans--;
			}
		}
		cout << ans << endl;
	}
}