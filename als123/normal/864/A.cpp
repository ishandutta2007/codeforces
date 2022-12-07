#include<cstdio>
const int N=105;
int n;
int a=-1,a_num=0;
int b=-1,b_num=0;
int main()
{
	scanf("%d",&n);
	bool tf=false;
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		if (a==-1)
		{
			a=x;
			a_num++;
		}
		else if (x==a)	a_num++;
		else if (b==-1)
		{
			b=x;b_num++;
		}
		else if (x==b) b_num++;
		else tf=true;
	}
	if (tf||a_num!=b_num) printf("NO\n");
	else
	{
		printf("YES\n%d %d\n",a,b);
	}
	return 0;
}