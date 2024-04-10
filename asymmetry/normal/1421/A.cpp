#include <bits/stdc++.h>

using namespace std;

int a, b, gh;

void solve()
{
	scanf("%d%d", &a, &b);
	int x=0;
	for(int i=0; i<31; ++i)
	{
		if(a&(1<<i) || b&(1<<i))
		{
			x^=1<<i;
		}
	}
	printf("%d\n", (a^x)+(b^x));
}

int main()
{
	scanf("%d", &gh);
	while(gh--)
	{
		solve();
	}
	return 0;
}