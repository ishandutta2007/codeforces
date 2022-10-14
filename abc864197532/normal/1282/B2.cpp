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
	int t;
	cin >> t;
	while (t--) {
		int n,k;
		lli p;
		cin >> n >> p >> k;
		int a[n];
		fop (i,0,n) cin >> a[i];
		sort(a,a+n);
		lli firstK[k];
		firstK[0] = a[0];
		fop (i,1,k) firstK[i] = firstK[i-1] + a[i];
		int ans = 0;
		fop (i,0,k-1) {
			lli cost = firstK[i];
			if (cost > p) break;
			ans = max(ans, i + 1);
			int j;
			for (j = i + k; j < n; j += k) {
				cost += a[j];
				if (cost > p) break;
				else ans = max(ans, j + 1);
			}
		}
		lli cost = 0;
		for (int i = k - 1; i < n; i += k) {
			cost += a[i];
			if (cost > p) break;
			else ans = max(ans, i + 1);
		}
		cout << ans << endl;
	}
}