#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n,x,y,d,maxx=INT_MAX;
		cin >> n >> x >> y >> d;
		if (x%d!=y%d and y%d!=1 and y%d!=n%d) {
			cout << -1 << endl;
		} else {
			if (x%d==y%d) maxx=min(abs((y-x)/d),maxx);
			if (y%d==1) maxx=min((x+d-2)/d+(y-1)/d,maxx);
			if (y%d==n%d) maxx=min((n-x+d-1)/d+(n-y)/d,maxx);
			cout << maxx << endl;
		}
	}
}