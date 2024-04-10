#include<cstdio>
int x,t=1,r,y,ans[105];
int main()
{
	scanf("%d",&x);
	while(x--)
	{
		scanf("%d",&y);
		if(y<0)
		{
			if(r==2)r=1,t++;
			else r++;
		}
		ans[t]++;
	}
	printf("%d\n",t);
	for(x=1;x<t;x++)printf("%d ",ans[x]);
	printf("%d\n",ans[t]);
}