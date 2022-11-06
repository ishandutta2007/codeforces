//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int mod=1e9+7;
int taxi,n,a[200009],res,cnt;
long long ans=1;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		cnt=0;ans=1;
		for(int i=1;i<=n;i++)a[i]=read();res=a[1];
		for(int i=2;i<=n;i++)res=(res&a[i]);
		for(int i=1;i<=n;i++)
			if(a[i]==res)cnt++;
		ans=ans*cnt*(cnt-1)%mod;
		for(int i=1;i<=n-2;i++)ans=ans*i%mod;
		printf("%lld\n",ans);
	}
	return 0;
}