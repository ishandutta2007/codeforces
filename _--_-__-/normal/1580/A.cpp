#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m;
char A[405][405];
int psum[405][405];
int frec(int l0, int r0, int l1, int r1)
{
	return psum[r0][r1] - (l0 == 0 ? 0 : psum[l0 - 1][r1]) - (l1 == 0 ? 0 : psum[r0][l1 - 1]) + (l0 == 0 || l1 == 0 ? 0 : psum[l0 - 1][l1 - 1]);
}

int c0[405], c1[405];
int calc(int l, int r)
{
	rep(i, m) {
		c0[i] = (A[l][i] == '0') + (A[r][i] == '0') + frec(l + 1, r - 1, i, i);
		c1[i] = r - l - 1 - frec(l + 1, r - 1, i, i);
	}
	
	int ret = INF, tmp = INF;
	rep(i, m - 3) {
		tmp = min(tmp + c0[i], c1[i]);
		ret = min(ret, tmp + c0[i + 1] + c0[i + 2] + c1[i + 3]);
	}
	return ret;
}

void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", A[i]);
	rep(i, n) rep(j, m) psum[i][j] = A[i][j] == '1';
	rep(i, n) rep(j, m) psum[i][j + 1] += psum[i][j];
	rep(i, n) rep(j, m) psum[i + 1][j] += psum[i][j];
	
	int ans = INF;
	rep(l, n) for(int r = l + 4; r < n; r ++) ans = min(ans, calc(l, r));
	printf("%d\n", ans); 
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}