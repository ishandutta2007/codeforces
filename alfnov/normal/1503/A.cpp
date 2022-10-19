#include<bits/stdc++.h>
using namespace std;
char s[200005],a1[200005],a2[200005];
int n;
void check()
{
	int flag=1,he=0;
	for(int i=1;i<=n;i++)
	{
		if(a1[i]=='(')he++;
		else he--;
		if(he<0)flag=0;
	}
	if(he!=0)flag=0;
	he=0;
	for(int i=1;i<=n;i++)
	{
		if(a2[i]=='(')he++;
		else he--;
		if(he<0)flag=0;
	}
	if(he!=0)flag=0;
	if(!flag)puts("NO");
	else
	{
		puts("YES");
		printf("%s\n%s\n",a1+1,a2+1);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		scanf("%s",s+1);
		int gs=0;
		for(int i=1;i<=n;i++)gs+=(s[i]=='1');
		if(gs&1)
		{
			puts("NO");
			continue;
		}
		int dd=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				dd++;
				if(dd*2<=gs)a1[i]=a2[i]='(';
				else a1[i]=a2[i]=')';
			}else
			{
				if((i-dd)&1)a1[i]='(',a2[i]=')';
				else a1[i]=')',a2[i]='(';
			}
		}
		a1[n+1]=a2[n+1]=0;
		check();
	}
	return 0;
}