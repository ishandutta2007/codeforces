#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, k, ret;
int ans[1005][1005];

void solve(int l, int r, int dep)
{
	if(l >= r) return;
	ret = max(ret, dep);
	int tmp = (r - l + 1) / k, tn = (r - l + 1) % k;
	int cp = l;
	rep(i, k) {
		int cl = i < tn ? tmp + 1 : tmp;
		solve(cp, cp + cl - 1, dep + 1);
		cp += cl;
	}
	for(int i = l; i <= r; i ++) for(int j = i + 1; j <= r; j ++) if(ans[i][j] == 0) ans[i][j] = dep;
}

int main()
{
	scanf("%d%d", &n, &k);
	solve(0, n - 1, 1);
	printf("%d\n", ret);
	rep(i, n) for(int j = i + 1; j < n; j ++) printf("%d ", ans[i][j]);
	return 0;
}