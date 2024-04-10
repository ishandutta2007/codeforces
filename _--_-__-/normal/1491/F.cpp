#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, ans[2005];
int query(int u, int v)
{
	printf("? 1 1\n%d\n%d\n", u + 1, v + 1); fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}
int queryp(int u, int v)
{
	printf("? %d 1\n", u);
	rep(i, u) printf("%d ", i + 1); printf("\n");
	printf("%d\n", v + 1); fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}
void solve()
{
	scanf("%d", &n);
	int x;
	rep1(i, n - 1) if(queryp(i, i) != 0) {
		x = i; break;
	}
	int l = 0, r = x - 1;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(queryp(mid + 1, x)) r = mid;
		else l = mid + 1;
	}
	
	vector<int> ans;
	for(int i = 0; i < l; i ++) ans.push_back(i);
	for(int i = l + 1; i < x; i ++) ans.push_back(i);
	for(int i = x + 1; i < n; i ++) if(query(x, i) == 0) ans.push_back(i);
	
	printf("! %d", ans.size());
	rep(i, ans.size()) printf(" %d", ans[i] + 1); printf("\n");
	fflush(stdout);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}