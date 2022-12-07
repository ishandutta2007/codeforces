#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d;

void solve()
{
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	if(a>b*c)
	{
		printf("-1\n");
		return;
	}
	b*=d;
	long long y=a/b+1;
	printf("%lld\n", y*a-y*(y-1)/2*b);
}

int main()
{
	int gh;
	scanf("%d", &gh);
	while(gh--)
	{
		solve();
	}
	return 0;
}