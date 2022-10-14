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
#define X first
#define Y second

int main () {
	int t;
	cin >> t;
	while (t--) {
		lli a, b;
		cin >> a >> b;
		lli g = __gcd(a, b);
		b /= g;
		set <lli> s1;
		lli k = b, ans = b;
		for (lli i = 2; i * i <= b; ++i) {
			if (k % i == 0) {
				ans -= (ans / i);
				while (k % i == 0) k /= i;
			}
		}
		if (k > 1) ans -= (ans / k);
		cout << ans << endl;
	}
}