#include <bits/stdc++.h>

using namespace std;

int n, a, b, c;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		while(b)
		{
			if(a<=20)
			{
				break;
			}
			a>>=1;
			a+=10;
			--b;
		}
		if(a<=c*10)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}