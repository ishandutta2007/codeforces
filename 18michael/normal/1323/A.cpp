#include<cstdio>
int n,ans,Test_num;
int a[102];
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			if(!(a[i]&1))
			{
				ans=i;
				break;
			}
		if(ans)printf("1\n%d\n",ans);
		else
		{
			if(n==1)puts("-1");
			else printf("2\n1 2\n");
		}
	}
	return 0;
}