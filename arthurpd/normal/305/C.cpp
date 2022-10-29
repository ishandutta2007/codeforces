#include <stdio.h>
#include <map>
using namespace std;

int mx;
map<int,int> a;

void add(int x)
{
	mx = max(mx, x);
	if(a[x] == 0)
		a[x]++;
	else
	{
	 	a.erase(x);
		add(x+1);
	}
}


int
main(void)
{
	int n, i, x, ans = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		add(x);
	}
	printf("%d\n", (mx+1) - a.size());
	return 0;
}