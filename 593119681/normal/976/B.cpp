#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
LL k;

int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	if (k < n) printf("%lld 1\n", k + 1);
	else
	{
		LL r = (k - n) / (m - 1);
		LL c = (k - n) % (m - 1);
		if (r & 1)
			printf("%lld %lld\n", n - r, (m - 1) - c + 1);
		else printf("%lld %lld\n", n - r, c + 2);
	}
	return 0;
}