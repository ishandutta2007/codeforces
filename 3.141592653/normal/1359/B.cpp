#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
void exec()
{
	int n,m,x,y;
	char str[1111];
	scanf("%d%d%d%d",&n,&m,&x,&y);
	if(y>2*x)y=x*2;
	register int i,ii;
	int ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(ii=1;ii<=m;ii++)
		{
			if(ii<m&&str[ii]=='.'&&str[ii+1]=='.')
				ans+=y,ii++;
			else if(str[ii]=='.')ans+=x;
		}
	}printf("%d\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/