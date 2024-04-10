#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>


int main () {
	cout << "? ";
	fop (i,1,101) cout << i << ' ';
	cout << endl;
	fflush(stdout);
	lli a,b;
	cin >> a;
	lli m = 1 << 14 - 1;
	cout << "? ";
	fop (i,1,101) cout << (i << 7) << ' ';
	cout << endl;
	fflush(stdout);
	cin >> b;
	lli ans=0;
	fop (i,7,14) {
		if (a & (1ll << i)) {
			ans += (1 << i);
		}
	}
	fop (i,0,7) {
		if (b & (1ll << i)) {
			ans += (1 << i);
		}
	}
	cout << "! " << ans << endl;
	fflush(stdout);
}