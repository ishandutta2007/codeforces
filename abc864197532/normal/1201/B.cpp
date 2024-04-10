#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)


int main () {
	int n;
	lli a,t=0,q=0;
	cin >> n;
	fop(i,0,n) {
		cin >> a;
		if (t<a) t=a;
		q+=a;
	} if (q%2==0 and t*2<=q) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}