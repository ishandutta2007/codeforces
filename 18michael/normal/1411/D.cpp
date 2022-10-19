#include<bits/stdc++.h>
using namespace std;
long long n,i,l0,r0,x,y,t=0,r=0,res,ans;char s[100002];
int main()
{
	scanf("%s%lld%lld",s,&x,&y),n=strlen(s);
	for(i=0;i<n;++i)
	{
		if(s[i]!='1')r+=(i-t)*y,++t;
		else r+=t*x;
	}
	for(ans=res=r,i=0,l0=0,r0=t;i<n;++i)
	{
		if(s[i]=='0')++l0,--r0;
		if(s[i]=='?')--r0,ans=min(ans,res=res-(i-l0)*y-(n-i-1-r0)*x+l0*x+r0*y);
	}
	for(res=r,i=n-1,l0=t,r0=0;~i;--i)
	{
		if(s[i]=='0')--l0,++r0;
		if(s[i]=='?')--l0,ans=min(ans,res=res-(i-l0)*y-(n-i-1-r0)*x+l0*x+r0*y);
	}
	return 0&printf("%lld",ans);
}