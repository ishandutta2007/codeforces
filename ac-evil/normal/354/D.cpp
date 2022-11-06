#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i, a, b) for (int i = a, i##end = b; i <= i##end; ++i)
#define per(i, a, b) for (int i = a, i##end = b; i >= i##end; --i)
#define rep0(i, a) for (int i = 0, i##end = a; i < i##end; ++i)
#define per0(i, a) for (int i = a-1; ~i; --i)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define fst first
#define snd second

const int inf = 0x3fffffff;

const int maxn = 100000 + 5, maxh = 800;

int n, k;
int f[maxh], g[maxh];
vector<int> P[maxn];

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, k) {
		int x, y;
		scanf("%d%d", &x, &y);
		P[y].push_back(n-x+1);
	}
	
	rep(i, 1, n) sort(P[i].begin(), P[i].end());
	
	int hgt = sqrt(6*k)+5;
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	
	rep(i, 1, n) {
		memcpy(g, f, sizeof f);
		memset(f, 0x3f, sizeof f);
		int minf = 0, pt = 0;
		rep(j, 0, hgt) {
			if (pt < P[i].size() && P[i][pt] == j) pt++;
			if (g[j] < g[minf]) minf = j;
			f[j] = min(g[j+1], g[minf] + (j ? j*(j+1)/2 + 2 : 0)) + (P[i].size()-pt)*3;
		}
	}

	int ans = inf;
	rep(i, 0, hgt) chkmin(ans, f[i]);
	printf("%d", ans);
	
	return 0;
}