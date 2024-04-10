#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

bool ok[100005];
void solve()
{
	int n, m, a, b, c;
	scanf("%d%d", &n, &m);
	rep1(i, n) ok[i] = true;
	rep(i, m) {
		scanf("%d%d%d", &a, &b, &c);
		ok[b] = false;
	}
	rep1(i, n) if(ok[i]) {
		rep1(j, n) if(i != j) printf("%d %d\n", i, j);
		return;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}