//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,k,res,ans,now,kk;
signed main()
{
	n=read(),k=read();
	if(k>=1e8)
	{
		puts("-1");return 0;
	}
	else if(k*(k+1)/2>n)
	{
		puts("-1");return 0;
	}
	res=k*(k+1)/2;kk=n/res;now=n;ans=1;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0&&kk>=i)ans=max(ans,i);
		if(n%i==0&&kk>=n/i)ans=max(ans,n/i);
	}
	for(int i=1;i<=k-1;i++)
	{
		printf("%lld ",i*ans);
		now-=i*ans;
	}
	cout<<now<<endl;
	return 0;
}