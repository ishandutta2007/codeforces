#include<bits/stdc++.h>
#define eps 1e-10
using namespace std;
int n,k,t,t1=1,ans,res;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(k),t=(int)(log(n)/log(k)+eps),printf("%d\n",t+=(pow(k,t)<n));
	for(int i=1;i<t;++i)t1*=k;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		{
			for(ans=1,res=t1;i/res==j/res;++ans,res/=k);
			printf("%d ",ans);
		}
	return 0;
}