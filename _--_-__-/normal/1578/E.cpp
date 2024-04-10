#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[105];
bool isp(int x)
{
	for(int i = 2; i * i <= x; i ++) if(x % i == 0) return false;
	return true;
}
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	int sum = 0;
	rep(i, n) sum += a[i];
	if(isp(sum)) {
		int mn = MOD;
		rep(i, n) if(a[i] & 1) mn = min(mn, a[i]);
		printf("%d\n", n - 1);
		rep(i, n) if(mn != a[i]) printf("%d ", i + 1); printf("\n");
	} else {
		printf("%d\n", n);
		rep(i, n) printf("%d ", i + 1); printf("\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}