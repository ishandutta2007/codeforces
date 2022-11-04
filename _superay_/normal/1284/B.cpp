#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
vector<int> vec[N];
vector<int> bad;
int ok[N];
int main() {
	scanf("%d", &n);
	long long ans = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int sz;
		scanf("%d", &sz);
		vec[i].resize(sz);
		for (int j = 0; j < sz; j++)
			scanf("%d", &vec[i][j]);
		ok[i] = 0;
		for (int j = 1; j < sz; j++) {
			if (vec[i][j - 1] < vec[i][j]) {ok[i] = 1; break;}
		}
		if (ok[i]) ans += n, cnt++;
		else {
			bad.push_back(vec[i][0]);
		}
	}
	sort(bad.begin(), bad.end());
	for (int i = 1; i <= n; i++) if (!ok[i]) {
		ans += cnt;
		int cur = vec[i][(int)vec[i].size() - 1];
		ans += bad.size() - (upper_bound(bad.begin(), bad.end(), cur) - bad.begin());
	}
	cout << ans << endl;
	return 0;
}