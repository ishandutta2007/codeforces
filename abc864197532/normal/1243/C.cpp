#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
 
int main () {
	lli n;
	cin >> n;
	lli tmp = -1;
	for (lli i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			if (tmp == -1) {
				tmp = i;
				break;
			}
		}
	}
	if (tmp == -1) {
		cout << n << endl;
	} else {
		lli ans = 1;
		while (ans < n) {
			ans *= tmp;
		}
		if (ans == n) {
			cout << tmp << endl; 
		} else {
			cout << 1 << endl;
		}
	}
	return 0;
}