#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= k - 3; i++)
			printf("1 ");
		n -= (k - 3);
		int p = 1;
		while(!(n & 1))
			n >>= 1, p <<= 1;
		if(n == 1)
			printf("%d %d %d\n", p >> 2, p >> 2, p >> 1);
		else
			printf("%d %d %d\n", p, ((n - 1) >> 1) * p, ((n - 1) >> 1) * p);
	}
	return 0;
}