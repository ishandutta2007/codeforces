#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int t;
	cin >> t;
	while (t--) {
		int a,b,n;
		cin >> a >> b >> n;
		if (n%3==0) cout << a << endl;
		else if (n%3==1) cout << b << endl;
		else cout << (a^b) << endl;
	}
}