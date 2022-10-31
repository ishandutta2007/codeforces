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
		int q = k / (n - 1), r = k % (n - 1);
		if(r == 0)
			printf("%d\n", n * q - 1);
		else
			printf("%d\n", n * q + r);
	}
	return 0;
}