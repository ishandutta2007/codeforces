#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int main()
{
	int T, a, b;
	scanf("%d", &T);
	while(T --) {
		scanf("%d%d", &a, &b);
		printf("%d\n", (a ^ b) & 1 ? -1 : (a == 0 && b == 0 ? 0 : (a == b ? 1 : 2)));
	}
	return 0;
}