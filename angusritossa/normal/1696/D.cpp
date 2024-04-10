#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define MAXN 300010
int n, a[MAXN];
pair<int, int> mx[MAXN][2], mn[MAXN][2];
int doThing(int at, bool isMn, int dir) {
	if (dir == 1 && at == n-1) return 0;
	if (dir == 0 && at == 0) return 0;

	D("here %d %d %d\n", at, (int)isMn, dir);
	if (isMn) {
		return 1+doThing(mx[at][dir].second, !isMn, dir);
	} else {
		return 1+doThing(mn[at][dir].second, !isMn, dir);
	}
}
void solve() {
	scanf("%d", &n);
	pair<int, int> mxx = { 0, 0 };
	pair<int, int> mnn = { 1e9, 1e9 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mxx = max(mxx, { a[i], i });
		mnn = min(mnn, { a[i], i });
		mx[i][0] = mxx;
		mn[i][0] = mnn;
	}
	if (n == 1) {
		printf("0\n");
		return;
	}
	mxx = { 0, 0 };
	mnn = { 1e9, 1e9 };
	for (int i = n-1; i >= 0; i--) {
		mxx = max(mxx, { a[i], i });
		mnn = min(mnn, { a[i], i });
		mx[i][1] = mxx;
		mn[i][1] = mnn;
	}
	int ans1 = doThing(mn[0][1].second, 1, 0) + doThing(mx[0][1].second, 0, 1) + 1;
	int ans2 = doThing(mn[0][1].second, 1, 1) + doThing(mx[0][1].second, 0, 0) + 1;
	int ans = min(ans1, ans2);
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}