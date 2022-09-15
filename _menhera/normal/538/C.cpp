#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	int ft,fh;
	scanf("%d%d",&ft,&fh);
	int ans=fh+ft-1;
	for(int i=1;i<M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int free=x-ft-abs(y-fh);
		if(free<0)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		ans=max(ans,max(y,fh)+free/2);
		ft=x;fh=y;
	}
	ans=max(N-ft+fh,ans);
	printf("%d",ans);
	return 0;
}