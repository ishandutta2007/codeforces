#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n, m, a[4005], cnt;
LL dp[4005][4005];

int solve(int l, int r, int id)
{
	int mid = l;
	for(int i = l + 1; i <= r; i ++) if(a[i] < a[mid]) mid = i;
	int siz;
	if(l == r) {
		siz = 0;
		dp[id][0] = 0;
	} else if(mid == l) {
		int tmp = cnt;
		siz = solve(mid + 1, r, cnt ++) ;
		for(int i = 0; i <= cnt; i ++) dp[id][i] = dp[tmp][i];
	} else if(mid == r) {
		int tmp = cnt;
		siz = solve(l, mid - 1, cnt ++) ;
		for(int i = 0; i <= cnt; i ++) dp[id][i] = dp[tmp][i];
	} else {
		int tl = cnt;
		int ls = solve(l, mid - 1, cnt ++);
		int tr = cnt;
		int rs = solve(mid + 1, r, cnt ++);
		siz = ls + rs;
		for(int i = 0; i <= siz; i ++) dp[id][i] = -INF;
		for(int i = 0; i <= ls; i ++) for(int j = 0; j <= rs; j ++)
		dp[id][i + j] = max(dp[id][i + j], dp[tl][i] + dp[tr][j] - 2LL * i * j * a[mid]);
	}
	
	siz ++; dp[id][siz] = -INF;
	for(int i = siz; i >= 1; i --) dp[id][i] = max(dp[id][i], dp[id][i - 1] + 1LL * (m + 1 - 2 * i) * a[mid]);
	return siz;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	
	cnt = 1;
	solve(0, n - 1, 0);
	printf("%lld\n", dp[0][m]);
	return 0;
}