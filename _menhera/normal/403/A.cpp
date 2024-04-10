#include<cstdio>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int con[50][50];
		int n,p;
		scanf("%d%d",&n,&p);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				con[i][j]=0;
		for(int i=0;i<n;i++)
		{
			printf("%d %d\n",i+1,(i+1)%n+1);
			con[i][(i+1)%n]=1;
			con[(i+1)%n][i]=1;
		}
		for(int i=0;i<n;i++)
		{
			printf("%d %d\n",i+1,(i+2)%n+1);
			con[i][(i+2)%n]=1;
			con[(i+2)%n][i]=1;
		}
		int cnt=0;
		if(p==0) goto end;
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				if(!con[x][y])
				{
					printf("%d %d\n",x+1,y+1);
					if(++cnt==p)
						goto end;
				}
			}
		}
		end:
		0;
	}
}