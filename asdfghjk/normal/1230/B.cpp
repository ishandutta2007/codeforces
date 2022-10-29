#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,K,i;
char s[200005];
int main()
{
//	freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);
	scanf("%d%d%s",&n,&K,s+1);
	if(K==0)
	{
		printf("%s",s+1);
		return 0;
	}
	if(n==1)
	{
		printf("0");
		return 0;
	}
	if(s[1]>'1')
	{
		s[1]='1';
		--K;
	}
	for(i=2;i<=n&&K>0;++i)
	{
		if(s[i]>'0')
			s[i]='0',--K;
	}
	printf("%s",s+1);
	return 0;
}