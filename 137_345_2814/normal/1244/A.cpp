#include<cstdio>
using namespace std;
int T,a,b,c,d,e;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		int s1=(a-1)/c+1;
		int s2=(b-1)/d+1;
		if(s1+s2>e)printf("-1\n");
		else printf("%d %d\n",s1,s2);
	}
}