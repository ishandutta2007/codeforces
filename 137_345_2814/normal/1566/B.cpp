#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100500
int T,n;
char s[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);n=strlen(s+1);
		int mn=n+1,mx=0;
		for(int i=1;i<=n;i++)if(s[i]=='0')mn=min(mn,i),mx=max(mx,i);
		if(!mx)printf("0\n");
		else
		{
			int fg=1;
			for(int i=mn;i<=mx;i++)if(s[i]=='1')fg=0;
			printf("%d\n",fg?1:2);
		}
	}
}