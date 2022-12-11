#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;scanf("%d",&n);
	if(n==1)
	{
		puts("-1");
		return;
	}
	putchar('2');
	for(int i=1;i<n;i++)putchar('3');
	puts("");
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
	return 0;
}