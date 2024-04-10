#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int n, m;
int a[100005];

int main()
{
	scanf("%d%d", &n, &m);
	int ans = 0, cur = 0;
	rep(i, n) {
		scanf("%d", &a[i]);
		if(i == 0) cur = 1;
		else cur = a[i] == a[i - 1] ? 1 : cur + 1;
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
	return 0;
}