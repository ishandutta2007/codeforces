#include<bits/stdc++.h>
using namespace std;
char ans[10101];
char buf[10];
int main()
{
	int n;
	scanf("%d",&n);
	int x=1,y=1;
	for(int i=1;i<=n-1;i++)
	{
		printf("? %d %d %d %d\n",x+1,y,n,n);
		fflush(stdout);
		scanf("%s",buf);
		if(buf[0]=='Y')
		{
			ans[x+y-2]='D';
			x++;
			continue;
		}
		else
		{
			ans[x+y-2]='R';
			y++;
			continue;
		}
	}
	x=n,y=n;
	for(int i=1;i<=n-1;i++)
	{
		printf("? %d %d %d %d\n",1,1,x,y-1);
		fflush(stdout);
		scanf("%s",buf);
		if(buf[0]=='Y')
		{
			ans[x+y-3]='R';
			y--;
			continue;
		}
		else
		{
			ans[x+y-3]='D';
			x--;
			continue;
		}
	}
	printf("! %s\n",ans);
	fflush(stdout);
	return 0;
}