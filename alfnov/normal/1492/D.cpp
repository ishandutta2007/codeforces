#include<bits/stdc++.h>
using namespace std;
char s[1000005],t[1000005];
int main()
{
	int a,b,k;
	cin>>a>>b>>k;
	if(k==0)
	{
		puts("Yes");
		for(int i=1;i<=b;i++)printf("1");
		for(int i=1;i<=a;i++)printf("0");
		puts("");
		for(int i=1;i<=b;i++)printf("1");
		for(int i=1;i<=a;i++)printf("0");
		puts("");
		return 0;
	}
	if(a==0||b==1)
	{
		puts("No");
		return 0;
	}
	if(k>a+b-2)puts("No");
	else
	{
		puts("Yes");
		for(int i=1;i<=a+b;i++)s[i]=t[i]='0';
		s[1]=t[1]='1';
		s[2]=t[k+2]='1';
		int gs=2;
		for(int i=3;i<=a+b;i++)if(gs<b&&(s[i]=='0'&&t[i]=='0'))gs++,s[i]=t[i]='1';
		printf("%s\n%s\n",s+1,t+1);
	}
	return 0;
}