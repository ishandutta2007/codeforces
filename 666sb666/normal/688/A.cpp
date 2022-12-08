#include<cstdio>
#include<cstring>
const int maxn=101;
int n,d,day=0,ans=0;
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=d;i++)
	{
		char s[maxn];
		bool flag=false;
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;j++)if(s[j]=='0')flag=true;
		if(flag)day++;
		else day=0;
		if(day>ans)ans=day;
	}
	printf("%d\n",ans);
	return 0;
}