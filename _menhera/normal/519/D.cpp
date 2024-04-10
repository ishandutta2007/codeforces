#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int cost[255];
char str[100100];
long long sum[100100];
map<long long,int>hunyatt[26];
int main()
{
	str[0]='@';
	for(char i='a';i<='z';i++)
		scanf("%d",&cost[i]);
	scanf("%s",str+1);
	int len=strlen(str);
	for(int i=1;i<len;++i)
		sum[i]=sum[i-1]+cost[str[i]];
	long long ans=0;
	for(int i=len-1;i>=1;i--)
	{
		ans+=hunyatt[str[i]-'a'][sum[i]];
		hunyatt[str[i]-'a'][sum[i-1]]=
		hunyatt[str[i]-'a'][sum[i-1]]+1;
	}
	printf("%I64d",ans);
}