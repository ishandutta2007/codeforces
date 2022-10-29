#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,j,len;
char s[1000005],ans[1000005];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n<=3)
	{
		printf("%c",s[1]);
		return 0;
	}
	for(i=1,j=n;2*len+1<n/2;)
	{
		if(s[i]==s[j])
		{
			ans[++len]=s[i];
			++i,--j;
		}
		else if(s[i+1]==s[j])
		{
			ans[++len]=s[j];
			i+=2,--j;
		}
		else if(s[i]==s[j-1])
		{
			ans[++len]=s[i];
			++i,j-=2;
		}
		else if(s[i+1]==s[j-1])
		{
			ans[++len]=s[i+1];
			i+=2,j-=2;
		}
		else
			++i;
	}
	for(i=1;i<=len;++i)
		printf("%c",ans[i]);
	if(2*len+1==n/2)
		printf("%c",s[j]);
	for(i=len;i>=1;--i)
		printf("%c",ans[i]);
	return 0;
}