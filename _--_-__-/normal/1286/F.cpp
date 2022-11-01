#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
LL a[25], sum[1048576];
bool ok[1048576];
int ans[1048576];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%lld", &a[i]);
	rep(i, n) rep(j, 1 << n) if(j >> i & 1) sum[j] += a[i];
	rep(i, 1 << n) if(i > 0) {
		if(i == (i & -i) && sum[i] == 0) {
			ok[i] = true;
			continue;
		}
		int ci = i ^ (i & -i);
		for(int j = ci; j > 0; j = j - 1 & ci)
		if(max(sum[j] - sum[i ^ j], sum[i ^ j] - sum[j]) <= __builtin_popcount(i) - 1 &&
		(sum[j] - sum[i ^ j] - __builtin_popcount(i)) & 1) {
			ok[i] = true;
			break;
		}
	}
	
	rep(i, 1 << n) if(ok[i]) {
		int ci = (1 << n) - 1 ^ i;
		for(int j = ci; j > 0; j = j - 1 & ci)
		ans[j | i] = max(ans[j | i], ans[j] + 1);
		ans[i] = max(ans[i], 1);
	}
	
	printf("%d\n", n - ans[(1 << n) - 1]);
	return 0;
}