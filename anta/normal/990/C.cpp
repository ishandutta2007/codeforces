#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }

int main() {
	int n;
	while (~scanf("%d", &n)) {
		map<int, vector<int>> a;
		for (int i = 0; i < n; ++ i) {
			char buf[300001];
			scanf("%s", buf);
			int cur = 0, mi = 0;
			for (const char *p = buf; *p; ++ p) {
				if (*p == '(')
					++ cur;
				else
					-- cur;
				amin(mi, cur);
			}
			a[cur].push_back(mi);
		}
		for(auto &p : a)
			sort(p.second.begin(), p.second.end());
		long long ans = 0;
		for (auto p : a) {
			auto it = a.find(-p.first);
			if (it == a.end()) continue;
			const auto &v = it->second;
			int x = (int)count(p.second.begin(), p.second.end(), 0);
			int y = (int)(v.end() - lower_bound(v.begin(), v.end(), -p.first));
			ans += (long long)x * y;
		}
		printf("%lld\n", ans);
	}
}