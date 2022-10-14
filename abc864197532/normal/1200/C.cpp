#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;

int main () {
	lli n,m,x1,x2,y1,y2;
	int t;
	cin >> n >> m >> t;
	lli g=__gcd(n,m);
	lli n1=n/g,m1=m/g;
	fop (i,0,t) {
		cin >> x1 >> x2 >> y1 >> y2;
		x2--; y2--;
		if (x1==1) x2/=n1;
		if (x1==2) x2/=m1;
		if (y1==1) y2/=n1;
		if (y1==2) y2/=m1;
		if (y2==x2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}