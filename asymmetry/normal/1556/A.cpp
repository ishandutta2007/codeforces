//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if((a&1) != (b&1))
	{
		printf("-1\n");
		return;
	}
	if(a==b)
	{
		if(a==0)
		{
			printf("0\n");
		}
		else printf("1\n");
	}
	else
	{
		printf("2\n");
	}
}

int main()
{
	//~ ios_base::sync_with_stdio(false);
	//~ cin.tie(NULL);
	int q=1;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}