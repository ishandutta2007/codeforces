#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<long long, int>> c;
int fld[600020] = { 0 };
int qqq[300000];
int main() {
	int n, k, i, mm;
	long long ans = 0LL;
	pair<long long, int> t;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%I64d", &t.first);
		t.second = i + 1;
		c.push_back(t);
	}
	mm = k + 1;
	sort(c.begin(), c.end());
	for (i = n - 1; i >= 0; i--) {
		if (c[i].second > mm) {
			qqq[c[i].second] = c[i].second;
			fld[c[i].second] = 1;
		}
		else {
			qqq[c[i].second] = mm;
			fld[mm] = 1;
			ans += c[i].first * (long long)(mm - c[i].second);
			for (; fld[mm]; mm++);
		}
	}
	printf("%I64d\n", ans);
	for (i = 1; i <= n; i++) printf("%d ", qqq[i]);
}