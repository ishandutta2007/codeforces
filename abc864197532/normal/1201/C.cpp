#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n,m;
	cin >> n >> m;
	lli a[n];
	fop (i,0,n) cin >> a[i];
	sort(a,a+n);
	int now=(n+1)/2,med=(n-1)/2;
	while (true) {
		if (m>=(a[now]-a[med])*(now-med)) {
			m-=(a[now]-a[med])*(now-med);
			a[med]+=(a[now]-a[med]);
		} else {
			break;
		}
		now++;
		if (now==n) break;
	}
	a[med]+=(m/(now-med));
	cout << a[med] << endl;
}