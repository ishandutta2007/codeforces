#include <bits/stdc++.h>
#define pb push_back
using std::vector; using std::swap;
const int N = 200005;
int n, c[N];
struct node { int x, y; };
vector<node> ans;
int vis[N];
void dfs(int u, vector<int> &l) {
	if (vis[u]) return;
	vis[u] = 1; l.pb(u); dfs(c[u], l);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			vector<int> S, T;
			dfs(i, S);
			if (S.size() == 1) continue;
			for (int j = i + 1; j <= n; j++)
				if (!vis[j]) {
					T.clear();
					dfs(j, T);
					if (T.size() > 1) break;
				}
			if (T.size()) {
				int m1 = S.size(), m2 = T.size();
				ans.pb((node){S[0], T[0]});
				for (int i = 1; i < m1; i++) ans.pb((node){T[0], S[i]});
				for (int i = 1; i < m2; i++) ans.pb((node){S[0], T[i]});
				ans.pb((node){S[0], T[0]});
			} else {
				int m = S.size();
				if (m == 2) {
					int t = S[0] + S[1] == 3 ? 3 : S[0] == 1 || S[1] == 1 ? 2 : 1;
					ans.pb((node){t, S[0]}), ans.pb((node){t, S[1]}), ans.pb((node){t, S[0]});
				}
				else {
					ans.pb((node){S[m - 2], S[m - 1]}), ans.pb((node){S[m - 1], S[0]}), ans.pb((node){S[0], S[m - 2]});
					for (int i = 2; i < m; i++)
						ans.pb((node){S[i - 1], S[m - 1]});
				}
			}
		}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}