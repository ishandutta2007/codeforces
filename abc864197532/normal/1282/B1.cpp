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
		lli summ = 0;
		int ans = 0;
		for (int i = 0; i < n; i += 2) {
			summ += a[i];
			if (summ <= p) ans = max(ans, i + 1);
		}
		summ = 0;
		for (int i = 1; i < n; i += 2) {
			summ += a[i];
			if (summ <= p) ans = max(ans, i + 1);
		}
		cout << ans << endl;
	}
}