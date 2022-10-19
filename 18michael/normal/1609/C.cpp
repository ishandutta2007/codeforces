#include<bits/stdc++.h>
#define LL long long
#define Mx 1000000
using namespace std;
int n,e,Test_num,p_t=0,l,r,mid,L,R;
LL ans;
int a[1000002],p[1000002];
bool u[1000002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
int main()
{
	init(),read(Test_num);
	while(Test_num--)
	{
		read(n),read(e),ans=0;
		for(int i=1;i<=n;++i)
		{
			read(a[i]),a[i]=(a[i]==1? 0:(u[a[i]]? 2:1));
			if(i>e)a[i]+=a[i-e];
		}
		for(int i=1;i<=n;++i)
		{
			l=0,r=(n-i)/e;
			while(l<=r)
			{
				mid=((l+r)>>1);
				if(a[i+mid*e]-(i>e? a[i-e]:0)>1)r=mid-1;
				else l=mid+1;
			}
			R=r,l=0,r=(n-i)/e;
			while(l<=r)
			{
				mid=((l+r)>>1);
				if(a[i+mid*e]-(i>e? a[i-e]:0)>=1)r=mid-1;
				else l=mid+1;
			}
			L=max(0,r),ans+=max(R-L,0);
		}
		printf("%lld\n",ans);
	}
	return 0;
}