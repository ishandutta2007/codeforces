#include <iostream>
using namespace std;
int n,m;
char arr[505][505];
int count(int i,int j,int dx,int dy)
{
	if (i<0 || j<0 || i>=n || j>=m || arr[i][j]=='.')
	return 0;
	return 1+count(i+dx,j+dy,dx,dy);
}
int main()
{
	int cnt=0;
	scanf("%d%d",&n,&m);
	getchar();
	for (int i=0;i<n;i++)
	{
		gets(arr[i]);
		for (int j=0;j<m;j++)
		cnt+=(arr[i][j]=='*');
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			int tmp=0;
			for (int dx=-1;dx<=1;dx++)
			{
				for (int dy=-1;dy<=1;dy++)
				{
					if (abs(dx)+abs(dy)==1)
					{
						int cur=count(i,j,dx,dy);
						if (cur>1)
						tmp+=cur;
						else
						tmp=-1e9;
					}
				}
			}
			if (tmp-3==cnt)
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
}