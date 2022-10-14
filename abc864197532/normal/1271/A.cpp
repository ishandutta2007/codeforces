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
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	b = min(b,c);
	lli sum = 0;
	if (f > e) {
		int aa = min(b,d);
		sum += (1ll * aa * f);
		b -= aa;
		d -= aa;
		sum += (1ll * min(a,d) * e);
	} else {
		int aa = min(a,d);
		sum += (1ll * aa * e);
		a -= aa;
		d -= aa;
		sum += (1ll * min(b,d) * f);
	}
	cout << sum << endl;
}