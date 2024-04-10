// Problem: A. Find a Number
// Contest: Codeforces - 2018-2019 ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// Author: RedreamMer
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LL long long
#define PB push_back
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 1e5;
const int M = 100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
int read() {
	int x = 0, y = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
	for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
	return (y ? -x : x);
}

int a, b, dp[505][5005];
struct pii {
	int x, y, z;
} pre[505][5005];

void print(int n, int m) {
	if(!m) return;
	print(pre[n][m].x, pre[n][m].y);
	printf("%lld", pre[n][m].z);
}

signed main() {
	// freopen("in1.in", "r", stdin);
	a = read();
	b = read();
	memset(dp, 0x3f, sizeof(dp));
	queue<pii> qu;
	dp[0][0] = 0;
	qu.push((pii) {0, 0});
	// rep(i, 1, 9) dp[i % a][i] = 1, qu.push((pii) {i % a, i, 1});
	while(siz(qu)) {
		pii u = qu.front();
		qu.pop();
		rep(i, 0, 9) {
			int x = (u.x * 10 + i) % a, y = u.y + i;
			if(y > b || dp[x][y] <= u.z + 1) continue;
			dp[x][y] = u.z + 1;
			qu.push((pii) {x, y});
			pre[x][y] = (pii) {u.x, u.y, i};
		}
	}
	if(dp[0][b] > 1e9) {
		puts("-1");
		return 0;
	}
	print(0, b);
	return 0;
}