#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,h,m,k,t=0,mn=inf,ans,cnt=0;
int H[100002],M[100002];
struct aaa
{
	int pos,opt;
}a[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.pos<b.pos? 1:0;
}
int main()
{
	read(n),read(h),read(m),read(k),m>>=1;
	for(int i=1;i<=n;++i)
	{
		read(H[i]),read(M[i]),a[++t]=(aaa){(M[i]+1)%m,1},a[++t]=(aaa){(M[i]+k)%m,-1};
		if((M[i]+k)/m>(M[i]+1)/m)a[++t]=(aaa){0,1};
	}
	sort(a+1,a+t+1,cmp);
	if(a[1].pos)return 0&puts("0 0");
	for(int i=1,j;i<=t;i=j)
	{
		for(j=i;j<=t && a[j].pos==a[i].pos;++j)cnt+=a[j].opt;
		if(cnt<mn)mn=cnt,ans=a[i].pos;
	}
	printf("%d %d\n",mn,ans);
	for(int i=1,j;i<=n;++i)
	{
		for(j=ans;j<M[i]+1;j+=m);
		if(j<M[i]+k)printf("%d ",i);
	}
	return 0;
}