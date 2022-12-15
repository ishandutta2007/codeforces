#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int n,ans;
char s[1000010];
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1,j;i<=n;i=j+1)
	{
		j=i;
		int cnt=0;
		while(1)
		{
			if(j>n)break;
			if(s[j]=='(')cnt++;
			else cnt--;
			if(!cnt)break;
			j++;
		}
		if(cnt)
		{
			puts("-1");
			return 0;
		}
		if(s[i]==')')ans+=(j-i+1);
	}
	printf("%d\n",ans);
	return 0;
}