#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
int a[MAXN];
map<int, int> dp;
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0;  CASE < t; CASE++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		dp.clear();
		int val = 0;
		dp[0] = 0;
		int mx = 0;
		int cummax = 0;
		for (int i = 0; i < n; i++) {
			val ^= a[i];
			int am = 0;
			if (dp.find(val) != dp.end()) {
				am = dp[val]+1;
			}
			am = max(am, cummax);
			cummax = max(cummax, am);
			dp[val] = am;
			mx = max(mx, am);
		}
		printf("%d\n", n-mx);
	}
}