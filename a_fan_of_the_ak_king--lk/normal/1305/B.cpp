#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=100005,E=262144;
#define inf 2147483647
int n,i,j,t,s[N],p[N];
char c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%s",c+1);
	for(i=1;c[i];++i)
		if(c[i]=='('&&c[i+1]==')')
			break;
	if(!c[i])
	{
		puts("0");
		return 0;
	}
	puts("1");
	int n=strlen(c+1);
	for(i=1;c[i];++i)
	{
		s[i]=s[i-1];
		if(c[i]=='(')
			++s[i];
	}
	for(--i;i>=1;--i)
	{
		p[i]=p[i+1];
		if(c[i]==')')
			++p[i];
	}
	for(i=0;i<=n;++i)
		if(s[i]==p[i+1])
			break;
	cout<<s[i]*2<<endl;
	for(j=1;j<=i;++j)
		if(c[j]=='(')
			printf("%d ",j);
	for(j=i+1;j<=n;++j)
		if(c[j]==')')
			printf("%d ",j);
}