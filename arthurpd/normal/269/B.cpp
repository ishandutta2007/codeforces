#include <stdio.h>
#include <vector>
using namespace std;

int a[5123];
int n, m;

int bit[5123];

int insert(int pos, int x)
{
	for(int i = pos; i < 5123; i += -i&i)
		bit[i] = max(x, bit[i]);
}

int get(int pos)
{
	int retv = 0;
	for(int i = pos; i > 0; i -= -i&i)
		retv = max(bit[i], retv); 
	return retv;
}

int lis()
{
	for(int i = 0; i < n; i++)
		insert(a[i], get(a[i])+1);
	return get(5122);
}

int
main(void)
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d %*f", &a[i]);
	printf("%d\n", n - lis());
}