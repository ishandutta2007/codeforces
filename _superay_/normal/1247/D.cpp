#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005];
map<vector<pair<int, int> >, int> mp;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int t = a[i];
		vector<pair<int, int> > vec;
		for (int j = 2; j * j <= t; j++) if (t % j == 0) {
			int c = 0;
			while (t % j == 0) t /= j, c++;
			if (c % k)
				vec.push_back(make_pair(j, c % k));
		}
		if (t > 1) vec.push_back(make_pair(t, 1 % k));
		sort(vec.begin(), vec.end());
		mp[vec]++;
	}
	long long ans = 0;
	for (auto &it : mp) {
		vector<pair<int, int> > vec = it.first, nvec;
		nvec = vec;
		for (int i = 0; i < (int)nvec.size(); i++) {
			nvec[i].second = (k - nvec[i].second) % k;
		}
		map<vector<pair<int, int> >, int>::iterator it2 = mp.find(nvec);
		if (it2 != mp.end()) ans += 1ll * it.second * it2 -> second;
		if (nvec == vec) ans -= it.second;
	}
	assert(ans % 2 == 0);
	printf("%I64d\n", ans / 2);
	return 0;
}