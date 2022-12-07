//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);
	if(n&1)
	{
		printf("NO\n");
		return;
	}
	n/=2;
	if((int)sqrt(n)*(int)sqrt(n)==n)
	{
		printf("YES\n");
		return;
	}
	if(n&1)
	{
		printf("NO\n");
		return;
	}
	n/=2;
	if((int)sqrt(n)*(int)sqrt(n)==n)
	{
		printf("YES\n");
		return;
	}
	printf("NO\n");
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