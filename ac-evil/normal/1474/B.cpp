#include <bits/stdc++.h>
using std::vector; using std::lower_bound;
typedef long long LL;
const int N = 100005;
int T, n; char s[N];
bool check(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	return true;
}
vector<int> a;
int main() {
	for (int i = 2; i <= 30000; i++) if (check(i)) a.push_back(i);
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		int fac1 = a[lower_bound(a.begin(), a.end(), n+1) - a.begin()], fac2 = a[lower_bound(a.begin(), a.end(), fac1 + n) - a.begin()];
		//printf("%d %d\n", fac1, fac2);
		printf("%lld\n", (LL)fac1 * fac2);
	}
	return 0;
}