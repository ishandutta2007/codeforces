#include<bits/stdc++.h>
using namespace std;
const int M=998244853;
unsigned long long h[1000005],s[1000005];
long long h2[1000005],s2[1000005];
int n,q,i,p,ans[1000005],j;
char c[1000005];
int main()
{
	scanf("%d",&n);
	scanf("%s",c+1);
	s2[0]=s[0]=1;
	for(i=1;i<=n;++i)
	{
		h[i]=h[i-1]*23113+c[i]-'a';
		s[i]=s[i-1]*23113;
		h2[i]=(h2[i-1]*23213+c[i]-'a')%M;
		s2[i]=s2[i-1]*23213%M;
	}
	p=-1;
	for(i=(n+1)/2;i>=1;--i)
	{
		if(!((n&1)&&i==n/2+1))
			p+=2;
		for(j=p;j>-1;j-=2)
			if(h[i+j-1]-h[i-1]*s[j]==h[n-i+1]-h[n-i-j+1]*s[j]&&((h2[i+j-1]-h2[i-1]*s2[j])%M+M)%M==((h2[n-i+1]-h2[n-i-j+1]*s2[j])%M+M)%M)
				break;
		ans[i]=p=j;
	}
	for(i=1;i<=(n+1)/2;++i)
		printf("%d ",ans[i]);
}