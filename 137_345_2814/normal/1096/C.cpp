#include<cstdio>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==179){printf("360\n");continue;}
		int ans=-1;
		for(int i=3;i<=180;i++)
		{
			int fg=0;
			for(int j=1;j<i-1;j++)
			if(180*j/i==n&&180*j/i*i==180*j)
			fg=1;
			if(fg){ans=i;break;}
		}
		printf("%d\n",ans);
	}
}