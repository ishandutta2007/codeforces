#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int absv(int x)
{
	return x < 0 ? -x : x;
}

int n, a[100005];
vector<int> occ[2];
void solve()
{
	scanf("%d", &n);
	rep(i, 2) occ[i].clear();
	rep(i, n) {
		scanf("%d", &a[i]); a[i] &= 1;
		occ[a[i]].push_back(i);
	}
	
	LL ans = 0;
	if(occ[0].size() < occ[1].size()) swap(occ[0], occ[1]);
	if(occ[0].size() == occ[1].size() + 1) {
		rep(i, occ[0].size()) ans += absv(occ[0][i] - 2 * i);
		rep(i, occ[1].size()) ans += absv(occ[1][i] - 2 * i - 1);
	} else if(occ[0].size() == occ[1].size()) {
		LL cs = 0;
		rep(i, occ[0].size()) ans += absv(occ[0][i] - 2 * i);
		rep(i, occ[1].size()) ans += absv(occ[1][i] - 2 * i - 1);
		swap(occ[0], occ[1]);
		rep(i, occ[0].size()) cs += absv(occ[0][i] - 2 * i);
		rep(i, occ[1].size()) cs += absv(occ[1][i] - 2 * i - 1);
		ans = min(ans, cs);
	} else ans = -2;
	printf("%lld\n", ans / 2);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}