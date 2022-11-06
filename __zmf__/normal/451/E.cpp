//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int mod=1e9+7;
inline int Pow(int x,int y)
{
	int res=1,base=x%mod;
	while(y)
	{
		if(y&1)res=res*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return res;
}
int ans,n,s,a[29],kk=1;
inline int C(int m)
{
	if(m<n-1)return 0;
	int p1=1;
	for(int i=m;i>=m-n+2;i--)p1=(p1*(i%mod))%mod;
	return p1*kk;
}
signed main()
{
	n=read();s=read();
	for(int i=1;i<n;i++)kk=kk*i%mod;kk=Pow(kk,mod-2);
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=0;i<(1<<n);i++)
	{
		int cnt=0,now=n+s-1;
		for(int j=0;j<n;j++)
			if(i&(1<<j))cnt++,now=now-a[j]-1;
		if(cnt&1)ans=ans-C(now),ans=(ans+mod)%mod;
		else ans=(ans+C(now))%mod;
	//	cout<<cnt<<" "<<i<<" "<<now<<" "<<C(now)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}