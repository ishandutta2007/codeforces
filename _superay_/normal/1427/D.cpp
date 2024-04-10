#include <bits/stdc++.h>
using namespace std;
int n, a[60], na[60];
inline bool check() {
	for (int i = 1; i < n; i++) if (a[i] > a[i + 1]) return false;
	return true;
}
inline void Pro(vector<int> d) {
	int t = n;
	for (int i = 0, s = 0; i < (int)d.size(); i++) {
		for (int j = 1; j <= d[i]; j++) {
			na[t - d[i] + j] = a[s + j];
		}
		s += d[i];
		t -= d[i];
	}
	for (int i = 1; i <= n; i++) a[i] = na[i];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vector<vector<int> > ans;
	while (!check()) {
		vector<pair<int, int> > vec;
		for (int i = 1, j; i <= n; i = j) {
			for (j = i + 1; j <= n && a[j] == a[j - 1] + 1; j++);
			vec.push_back(make_pair(i, j - 1));
		}
		int fnd = 0;
		for (int i = 0; i < (int)vec.size(); i++) {
			for (int j = i + 1; j < (int)vec.size(); j++) if (a[vec[i].first] - 1 == a[vec[j].second]) {
				vector<int> ret;
				if (vec[i].first > 1) ret.push_back(vec[i].first - 1);
				ret.push_back(vec[i].second - vec[i].first + 1);
				ret.push_back(vec[j].second - vec[i].second);
				if (vec[j].second < n) ret.push_back(n - vec[j].second);
				Pro(ret);
				ans.push_back(ret);
				fnd = 1;
				break;
			}
			if (fnd) break;
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto &ret : ans) {
		printf("%d", (int)ret.size());
		for (int x : ret) printf(" %d", x);
		printf("\n");
	}
	return 0;
}