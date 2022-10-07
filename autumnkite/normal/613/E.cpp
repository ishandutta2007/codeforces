#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2005
#define P1 1000000007
#define P2 998244353
int n, m, pow1[N], pow2[N], dp[2][N][N], ans;
struct hash{
	int x, y;
	bool operator == (const hash &res) const {
		return x == res.x && y == res.y;
	}
};
struct str{
	char c[N];
	int len;
	hash pre[N], suf[N];
	void init(){
		scanf("%s", c + 1), len = strlen(c + 1);
		for (register int i = 1; i <= len; ++i){
			pre[i].x = (29ll * pre[i - 1].x + c[i] - 'a') % P1;
			pre[i].y = (31ll * pre[i - 1].y + c[i] - 'a') % P2;
		}
		for (register int i = len; i; --i){
			suf[i].x = (29ll * suf[i + 1].x + c[i] - 'a') % P1;
			suf[i].y = (31ll * suf[i + 1].y + c[i] - 'a') % P2;
		}
	}
	hash get(int l, int r){
		int x, y;
		if (l <= r){
			x = (pre[r].x - 1ll * pre[l - 1].x * pow1[r - l + 1] % P1 + P1) % P1;
			y = (pre[r].y - 1ll * pre[l - 1].y * pow2[r - l + 1] % P2 + P2) % P2;
		}
		else{
			x = (suf[r].x - 1ll * suf[l + 1].x * pow1[l - r + 1] % P1 + P1) % P1;
			y = (suf[r].y - 1ll * suf[l + 1].y * pow2[l - r + 1] % P2 + P2) % P2;
		}
		return (hash){x, y};
	}
	void rev(){
		std :: reverse(c + 1, c + 1 + len);
		std :: reverse(pre + 1, pre + 1 + len);
		std :: reverse(suf + 1, suf + 1 + len);
		for (register int i = 1; i <= len; ++i) std :: swap(pre[i], suf[i]);
	}
}s1, s2, t;
void add(int &x, int y){
	(x += y) >= P1 ? x -= P1 : 0;
}
int main(){
	pow1[0] = pow2[0] = 1;
	for (register int i = 1; i <= 2000; ++i)
		pow1[i] = 29ll * pow1[i - 1] % P1, pow2[i] = 31ll * pow2[i - 1] % P2;
	s1.init(), s2.init(), t.init();
	n = s1.len, m = t.len;
	dp[0][n + 1][0] = dp[1][n + 1][0] = 1;
	for (register int i = n; i; --i){
		dp[0][i][0] = dp[1][i][0] = 1;
		for (register int k = 2; k + k <= m && i + k - 1 <= n; ++k){
			hash t1 = s1.get(i, i + k - 1), t2 = s2.get(i, i + k - 1);
			hash t3 = t.get(m, m - k + 1), t4 = t.get(m - k - k + 1, m - k);
			if (t1 == t3 && t2 == t4) dp[1][i][k + k] = 1;
			if (t1 == t4 && t2 == t3) dp[0][i][k + k] = 1;
		}
	}
	for (register int i = n; i; --i)
		for (register int k = 1; k <= m; ++k){
			if (s1.c[i] == t.c[m - k + 1]) add(dp[0][i][k], dp[0][i + 1][k - 1]);
			if (s2.c[i] == t.c[m - k + 1]) add(dp[1][i][k], dp[1][i + 1][k - 1]);
			if (k > 1 && s1.c[i] == t.c[m - k + 1] && s2.c[i] == t.c[m - k + 2]) add(dp[0][i][k], dp[1][i + 1][k - 2]);
			if (k > 1 && s2.c[i] == t.c[m - k + 1] && s1.c[i] == t.c[m - k + 2]) add(dp[1][i][k], dp[0][i + 1][k - 2]);
		}
	for (register int i = 1; i <= n; ++i){
		add(ans, dp[0][i][m]), add(ans, dp[1][i][m]);
		for (register int k = 2; k + k <= m && i - k + 1 > 0; ++k){
			hash t1 = s1.get(i - k + 1, i), t2 = s2.get(i - k + 1, i);
			hash t3 = t.get(k, 1), t4 = t.get(k + 1, k + k);
			if (t1 == t3 && t2 == t4) add(ans, dp[1][i + 1][m - k - k]);
			if (t1 == t4 && t2 == t3) add(ans, dp[0][i + 1][m - k - k]);
		}
	}
	if (m == 1) return printf("%d\n", ans), 0;
	t.rev();
	memset(dp, 0, sizeof dp);
	dp[0][n + 1][0] = dp[1][n + 1][0] = 1;
	for (register int i = n; i; --i){
		dp[0][i][0] = dp[1][i][0] = 1;
		for (register int k = 2; k + k < m && i + k - 1 <= n; ++k){
			hash t1 = s1.get(i, i + k - 1), t2 = s2.get(i, i + k - 1);
			hash t3 = t.get(m, m - k + 1), t4 = t.get(m - k - k + 1, m - k);
			if (t1 == t3 && t2 == t4) dp[1][i][k + k] = 1;
			if (t1 == t4 && t2 == t3) dp[0][i][k + k] = 1;
		}
	}
	for (register int i = n; i; --i)
		for (register int k = 1; k <= m; ++k){
			if (s1.c[i] == t.c[m - k + 1]) add(dp[0][i][k], dp[0][i + 1][k - 1]);
			if (s2.c[i] == t.c[m - k + 1]) add(dp[1][i][k], dp[1][i + 1][k - 1]);
			if (m > 2 && k > 1 && s1.c[i] == t.c[m - k + 1] && s2.c[i] == t.c[m - k + 2]) add(dp[0][i][k], dp[1][i + 1][k - 2]);
			if (m > 2 && k > 1 && s2.c[i] == t.c[m - k + 1] && s1.c[i] == t.c[m - k + 2]) add(dp[1][i][k], dp[0][i + 1][k - 2]);
		}
	for (register int i = 1; i <= n; ++i){
		add(ans, dp[0][i][m]), add(ans, dp[1][i][m]);
		for (register int k = 2; k + k < m && i - k + 1 > 0; ++k){
			hash t1 = s1.get(i - k + 1, i), t2 = s2.get(i - k + 1, i);
			hash t3 = t.get(k, 1), t4 = t.get(k + 1, k + k);
			if (t1 == t3 && t2 == t4) add(ans, dp[1][i + 1][m - k - k]);
			if (t1 == t4 && t2 == t3) add(ans, dp[0][i + 1][m - k - k]);
		}
	}
	printf("%d\n", ans);
}