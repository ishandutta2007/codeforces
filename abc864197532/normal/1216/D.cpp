#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n;
	cin >> n;
	lli a[n];
	fop (i,0,n) cin >> a[i];
	sort(a,a+n);
	int b[n-1],g;
	fop (i,0,n-1) {
		b[i]=a[n-1]-a[i];
		if (i==0) g=b[i];
		else if (i!=0) g=__gcd(g,b[i]);
	}
	lli ans=0;
	fop (i,0,n-1) {
		ans+=b[i]/g;
	}
	cout << ans << ' ' << g << endl;
}