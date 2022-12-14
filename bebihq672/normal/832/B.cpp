#include<cstdio>
#include<cstring>
char b[33];
char s[101010],a[101010];
bool good[33];
int main()
{
	int Q;
	scanf("%s%s%d",b,s,&Q);
	int n=strlen(s);
	for(int i=0;i<strlen(b);i++)
		good[b[i]-'a']=1;
	while(Q--)
	{
		scanf("%s",a);
		int m=strlen(a);
		int tmp=0;
		bool flag=0;
		for(int i=0;i<n;i++)
		if(s[i]=='?')
		{
			if(i+tmp>=m)
			{
				flag=1;
				break;
			}
			if(good[a[i+tmp]-'a']!=1)
			{
				flag=1;
				break;
			}
		}
		else if(s[i]=='*')
		{
			tmp=m-n;
			if(m-n<-1)
			{
				flag=1;
				break;
			}
			for(int j=i;j<=i+tmp;j++)
			if(good[a[j]-'a']!=0)
			{
				flag=1;
				break;
			}
			if(flag)
				break;
		}
		else
		{
			if(i+tmp>=m)
			{
				flag=1;
				break;
			}
			if(s[i]!=a[i+tmp])
			{
				flag=1;
				break;
			}
		}
		if(m-n!=tmp)
			flag=1;
		if(flag==0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*
abc
a?a?a*
4
abacadc
abaca
apapa
aaaaax

*/