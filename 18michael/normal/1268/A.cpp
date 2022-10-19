#include<cstdio>
int n,k;
char s[200002];
inline bool check()
{
	for(int i=k;i<n;++i)
	{
		if(s[i]<s[i%k])return 1;
		if(s[i]>s[i%k])return 0;
	}
	return 1;
}
inline void add()
{
	for(int i=k-1;~i;--i)
	{
		if(s[i]<'9')
		{
			++s[i];
			break;
		}
		s[i]='0';
	}
}
int main()
{
	scanf("%d%d%s",&n,&k,s);if(!check())add();
	printf("%d\n",n);for(int i=0;i<n;++i)printf("%c",s[i%k]);
	return 0;
}