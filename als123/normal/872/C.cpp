#include<cstdio>

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		if (n%4==0) printf("%d\n",n/4);
		else if (n%4==1) 
		{
			int lalal=n/4;//
			if (lalal<2) printf("-1\n");
			else printf("%d\n",lalal-1);
		}
		else if (n%4==2) 
		{
			int lalal=n/4;
			if (lalal<1) printf("-1\n");
			else printf("%d\n",lalal);
		}
		else 
		{
			int lalal=n/4;
			if (lalal<3) printf("-1\n");
			else printf("%d\n",lalal-1);
		}
	}
	return 0;
}