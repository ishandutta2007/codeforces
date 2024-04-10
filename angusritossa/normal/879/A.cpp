#include <bits/stdc++.h>
using namespace std;
int n, sofar;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int s, k;
		scanf("%d%d", &s, &k);
		for (int i = s; true; i+=k)
		{
			if (i > sofar)
			{
				sofar = i;
				break;
			}
		}
	}
	printf("%d\n", sofar);
}