#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

struct fwt
{
	int dat[400005];
	void add(int id, int val)
	{
		for(; id > 0; id -= id & -id) dat[id] = (dat[id] + val) % MOD;
	}
	int query(int id)
	{
		int ret = 0;
		for(; id <= 400000; id += id & -id) ret = (ret + dat[id]) % MOD;
		return ret;
	}
}tre;
int n, t, b[200005], dp[200005];
PII dat[200005];
bool nd[200005];

int main()
{
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d%d", &dat[i].second, &dat[i].first); b[i] = dat[i].first;
	}
	sort(dat, dat + n);
	scanf("%d", &t);
	rep(i, t) {
		int x; scanf("%d", &x);
		nd[lower_bound(dat, dat + n, MP(b[x - 1], 0)) - dat] = true;
	}
	
	tre.add(2 * n, 1);
	rep(i, n) {
		dp[i] = tre.query(dat[i].second);
		tre.add(dat[i].second, dp[i]);
	}
	
	int pv = 1, ans = 0;
	for(int i = n - 1; i >= 0; i --) {
		tre.add(dat[i].second, (MOD - dp[i]) % MOD);
		if(nd[i] && dat[i].second >= pv) {
			ans = (ans + tre.query(pv)) % MOD;
			pv = dat[i].second;
		}
	}
	printf("%d\n", ans);
	return 0;
}