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
	lli a, b;
	cin >> a >> b;
	if ((a - b) & 1 or a > b) {
		cout << -1 << endl;
		return 0;
	}
	if (a == b) {
		if (a == 0) cout << 0 << endl;
		else cout << 1 << endl << a << endl;
		return 0;
	}
	lli x = (b - a) / 2;
	if ((a ^ x) + x == b) {
		cout << 2 << endl << (a ^ x) << ' ' << x << endl;
	} else {
		cout << 3 << endl << x << ' ' << x << ' ' << a << endl;
	}
}