#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[1005];
inline bool cmp(int i, int j) {
	return a[i] > a[j];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].first), a[i].second = i;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)
			if (a[i] > a[j])
				cnt++;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) {
		vector<int> b;
		for (int j = i + 1; j <= n; j++) if (a[i] > a[j]) b.push_back(j);
		sort(b.begin(), b.end(), cmp);
		for (int j = 0; j < (int)b.size(); j++) printf("%d %d\n", i, b[j]);
	}
	return 0;
}