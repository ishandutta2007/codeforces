#include<cstdio>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int fg=1;
		for(int i=0;i<=7;i++)
		for(int j=0;j<=7;j++)
		{
			if(!fg)break;
			int tp=n-3*i-5*j;
			if(tp<0||tp%7)continue;
			printf("%d %d %d\n",i,j,tp/7);fg=0;
		}
		if(fg)printf("-1\n");
	}
}