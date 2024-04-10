#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		LL a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a < c) printf("%d ", 1);
		else printf("%d ", -1);
		if (a * b > c) printf("%lld\n", b);
		else printf("%d\n", -1);
	}
	return 0;
}