#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n;
	cin >> n;
	int a[n];
	fop (i,0,n) cin >> a[i];
	sort(a,a+n);
	bool is=false;
	for (int i=n-2;i>=1;--i) {
		if (is) break;
		if (a[i]+a[i-1]>a[n-1]) {
			tie(a[i],a[n-1])=make_pair(a[n-1],a[i]);
			is=true;
		}
	}
	if (is) {
		cout << "YES" << endl;
		fop (i,0,n) {
			cout << a[i] << " \n" [i==n-1];
		}
	} else {
		cout << "NO" << endl;
	}
}