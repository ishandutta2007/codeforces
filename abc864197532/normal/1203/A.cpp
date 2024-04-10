#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int t;
	cin >> t;
	while (t--) {
		int n,from,k=0;
		cin >> n;
		int a[n];
		fop (i,0,n) {
			cin >> a[i];
			if (a[i]==1) k=i;
		}
		int may=1;
		from=k;
		while (true) {
			from++;
			if (from==n) from=0;
			may++;
			if (a[from]!=may) break;
		}
		if (may>=n) {
			cout << "YES" << endl;
			continue;
		} 
		may=1;
		from=k;
		while (true) {
			from--;
			if (from==-1) from=n-1;
			may++;
			if (a[from]!=may) break;
		}
		if (may>=n) {
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
		continue;
	}
}