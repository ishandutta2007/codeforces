#include <bits/stdc++.h>
using namespace std;

int main()
{   
	int n;
	scanf("%d",&n);
	int sum=0;
    int temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
		    scanf("%d",&temp);
			if(i==j)
			{
				sum+=temp;
			}
		}
	}
	sum%=2;

	int q;
	scanf("%d",&q);
	int a,b;
	string S="";
	for (int i = 0; i < q; ++i)
	{
		scanf("%d",&a);
		if(a==3)
		{
			printf("%d",sum);
		}
		else
		{
			scanf("%d",&b);
			sum^=1;
		}
	}

	return 0;
}