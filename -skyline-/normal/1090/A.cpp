#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int n, m[200005];
int tmx, mx[200005];
vector<int> hv[200005];
LL ans;

int main()
{
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &m[i]);
		hv[i].resize(m[i]);
		rep(j, m[i]) scanf("%d", &hv[i][j]);
	}
	rep(i, n) {
		rep(j, m[i]) mx[i] = max(mx[i], hv[i][j]);
		tmx = max(tmx, mx[i]);
	}
	rep(i, n) ans += 1LL * m[i] * (tmx - mx[i]);
	printf("%I64d\n", ans);
	return 0;
}