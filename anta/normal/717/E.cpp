#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

void dfs(int i, int p, const vector<vi> &g, vi &a, vi &ans) {
	for(int j : g[i]) if(j != p) {
		ans.push_back(j), a[j] *= -1;
		dfs(j, i, g, a, ans);
		ans.push_back(i), a[i] *= -1;
	}
	if(a[i] == -1) {
		if(p == -1) {
			assert(ans.back() == i);
			ans.pop_back(), a[i] *= -1;
		} else {
			ans.push_back(p), a[p] *= -1;
			ans.push_back(i), a[i] *= -1;
		}
	}
	assert(a[i] == 1);
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(count(a.begin(), a.end(), 1) == n) {
			puts("1");
			continue;
		}
		vi ans;
		ans.push_back(0);
		dfs(0, -1, g, a, ans);
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}