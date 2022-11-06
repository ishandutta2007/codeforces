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
const int N=1e5+9;
int n,A,cf,cm,m,nowm,l,r;
int a[N],sum[N],ans,res;
struct point
{
	int x,pos;
}b[N];
inline bool cmp(point xxx,point yyy)
{
	return xxx.x<yyy.x;
}
inline bool check(int x)
{
	int p=lower_bound(a+1,a+n+2,x)-a-1;
	int res=p*x-sum[p];
//	cout<<x<<" "<<p<<" "<<res<<endl;
	return res<=nowm;
}
inline int work()
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return res;
}
int mm,ff;
signed main()
{
	n=read(),A=read(),cf=read(),cm=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i].x=a[i],b[i].pos=i;
	sort(a+1,a+n+1);sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];sum[n+1]=sum[n]+A;res=0;
	for(int i=0;i<=n;i++)
	{
		a[n+1-i]=A;
		nowm=m;nowm-=(i*A-sum[n]+sum[n-i]);l=a[1],r=A;res=a[1];//cout<<nowm<<endl;
		if(nowm<0)continue;
		int km=work();
		int Mer=km*cm+cf*i;
		if(Mer>ans)
		{
			ans=Mer,mm=km,ff=i;
		//	cout<<Mer<<" "<<km<<" "<<i<<endl;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if(b[i].x<=mm)b[i].x=mm;
	for(int i=n;i>=n-ff+1;i--)b[i].x=A;
	for(int i=1;i<=n;i++)a[b[i].pos]=b[i].x;
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}