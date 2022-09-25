#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
char s[1233333];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s+1);
		int m1=0,m2=n,is=0;
		for(int i=1;i<=n;i++)
		if(s[i]=='1')
		{
			is=1;
			m1=i;
			if(m2==n)m2=i;
		}
		if(!is)printf("%d\n",n);
		else printf("%d\n",n*2-min(n-m1,m2-1)*2);
	}
}