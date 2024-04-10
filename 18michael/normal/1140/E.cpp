#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,k,ik,ik1,x;
int las[2]={};
LL sum[2],tmp[2]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	read(n),read(k),ik=Pow(k,mod-2),ik1=Pow(k-1,mod-2);
	read(x);if(~x)sum[1]=tmp[1]=1,las[1]=x;else sum[1]=k;
	read(x);if(~x)sum[0]=tmp[0]=1,las[0]=x;else sum[0]=k;
	for(int i=3,i1=1;i<=n;++i,i1^=1)
	{
		read(x);
		if(~x)
		{
			if(x==las[i1])tmp[i1]=(sum[i1]-tmp[i1])%mod;
			else
			{
				if(las[i1])tmp[i1]=(sum[i1]-(sum[i1]-tmp[i1])*ik1)%mod;
				else tmp[i1]=(((sum[i1]*ik)%mod)*(k-1))%mod;
				las[i1]=x;
			}
			sum[i1]=tmp[i1];
		}
		else tmp[i1]=(sum[i1]-tmp[i1])%mod,sum[i1]=(sum[i1]*(k-(i>2)))%mod;
	}
	return 0&printf("%lld",(((sum[0]*sum[1])%mod)+mod)%mod);
}