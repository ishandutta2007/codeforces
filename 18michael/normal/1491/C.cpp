#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num;LL sum,ans;
int a[5002];LL b[5002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),ans=sum=0;
		for(int i=1;i<=n;++i)read(a[i]),b[i]=0;
		for(int i=1;i<=n;++i)
		{
			b[i]+=b[i-1],sum+=b[i],++b[i+2],--b[min(i+a[i],n)+1];
			if(sum>=a[i]-1)sum-=(a[i]-1);
			else a[i]-=sum,sum=0,ans+=a[i]-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}