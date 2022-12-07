//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	long long x, y;
	scanf("%lld%lld", &x, &y);
	long long w;
	if(x>y)
	{
		w=(y/x+1)*x+y;
	}
	else
	{
		w=y-(y%x)/2;
	}
	printf("%lld\n", w);
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