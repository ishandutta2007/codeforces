#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

 
typedef pair<int,int> pii;
 
int constexpr max_n = 1e5 + 10;
 
int t, n;
 
void solve() {
	scanf(" %d", &n);
	long double a, b;
	vector<long double>x, y;
	for (int i = 0; i < 2 * n; i++) {
		scanf(" %Lf %Lf", &a, &b);
		if (a == 0)
			x.emplace_back(fabs(b));
		else
			y.emplace_back(fabs(a));
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long double ans = 0;
	for (int i = 0; i < n; i++)
		ans += sqrt((x[i] * x[i]) + (y[i] * y[i]));
	printf("%0.15Lf\n",ans);
}
 
int main() {
	scanf(" %d", &t);
	while (t--) {
		solve();
	}
}