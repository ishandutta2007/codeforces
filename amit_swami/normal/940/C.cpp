#include<bits/stdc++.h>
using namespace std;
int n,k,tot;
char s[520233],a[520233];
void print(int p)
{
	for(int i=1;i<p;++i)putchar(s[i]);
	for(int i=1;i<=tot;++i)
		if(s[p]==a[i])
		{
			putchar(a[i+1]);
			break;
		}
	for(int i=p+1;i<=k;++i)putchar(a[1]);
}
int main()
{
	scanf("%d%d%s",&n,&k,s+1);
	memcpy(a,s,sizeof a);
	sort(a+1,a+n+1);
	tot=unique(a+1,a+n+1)-a-1;
	if(n<k)
	{
		printf("%s",s+1);
		for(int i=n+1;i<=k;++i)putchar(a[1]);
	}
	else
		for(int i=k;i>=1;--i)
			if(s[i]<a[tot])
			{
				print(i);
				return 0;
			}
	return 0;
}