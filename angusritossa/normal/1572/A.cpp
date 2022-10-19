#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...)
#else
	#define D(x...)
#endif
#define MAXN 200010
set<int> s;
int t, n;
vector<int> required[MAXN];
vector<int> requiredRev[MAXN];
int numRequired[MAXN];
int getNext(int a) {
	auto it = s.upper_bound(a);
	if (it == s.end()) return *s.begin();
	return *it;
}
int main() {
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) required[i].clear(), requiredRev[i].clear();
		s.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &numRequired[i]);
			for (int j = 0; j < numRequired[i]; j++) {
				int a;
				scanf("%d", &a);
				required[i].push_back(a);
				requiredRev[a].push_back(i);
			}
			if (numRequired[i] == 0) {
				s.insert(i);
			}
		}
		int at = 0;
		int got = 0, ans = 1;
		while (s.size()) {
			int a = getNext(at);
			s.erase(a);
			if (a < at) ans++;
			got++;
			at = a;
			for (auto b : requiredRev[a]) {
				numRequired[b]--;
				if (!numRequired[b]) {
					s.insert(b);
				}
			}
		}
		if (got != n) ans = -1;
		printf("%d\n", ans);
	}
}