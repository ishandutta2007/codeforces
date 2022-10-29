#include <stdio.h>
#include <set>
using namespace std;
int n, k, a, m;

int ships(int x)
{
	return (x + 1) / (a + 1);
}

int main(void)
{
	int x;
	scanf("%d %d %d %d", &n, &k, &a, &m);
	set<int> div;
	div.insert(0);
	div.insert(n+1);
	int num = ships(n);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		set<int>::iterator r = div.upper_bound(x);
		set<int>::iterator l = r;
		l--;
		num -= ships(*r - *l - 1);
		num += ships(*r - x - 1) + ships(x - *l - 1);
		div.insert(x);
		if(num < k)
		{
			printf("%d\n", i+1);
			return 0;
		}
	}
	printf("-1\n");
}