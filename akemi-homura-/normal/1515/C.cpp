#include <bits/stdc++.h>
using namespace std;
int n, m, ans[100005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int lim;
		scanf("%d%d%d", &n, &m, &lim);
		set<pair<int, int> > st;
		for (int i = 1; i <= m; i++) st.insert(make_pair(0, i));
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			auto P = *st.begin();
			st.erase(st.begin());
			P.first += x;
			ans[i] = P.second;
			st.insert(P);
		}
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}