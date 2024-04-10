#include<bits/stdc++.h>
using namespace std;
int n,cc;
struct P{int x,y;}p[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++)if((p[i].x+p[i].y)%2)cc++;
	while(cc==0||cc==n)
	{
		cc=0;
		for(int i=1;i<=n;i++)
		{
			if((p[i].x+p[i].y)%2)p[i].y++;
			int x=p[i].x,y=p[i].y;
			p[i].x=(x+y)/2;p[i].y=(x-y)/2;
			if((p[i].x+p[i].y)%2)cc++;
		}
	}
	printf("%d\n",cc);
	for(int i=1;i<=n;i++)if((p[i].x+p[i].y)%2)printf("%d ",i);
	return 0;
}