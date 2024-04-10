#include <stdio.h>
#include <map>
using namespace std;
map<int,int> rdm;
int
main(void)
{
	int n, i, m, a, b, x, t = 1;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		t += (a*b);
		rdm[t] = i+1;
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d", &x);
		printf("%d\n", rdm.upper_bound(x)->second);
	}
	return 0;
}