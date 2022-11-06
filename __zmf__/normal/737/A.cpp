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
const int N=2e5+9;
int n,k,s,t,p[N],ans=2e9,sum[N],now;
struct point
{
	int c,v;
}a[N];
inline bool cmp(point xxx,point yyy)
{
	if(xxx.v!=yyy.v)return xxx.v>yyy.v;
	else return xxx.c<yyy.c;
}
signed main()
{
	n=read();k=read(),s=read(),t=read();
	for(int i=1;i<=n;i++)a[i].c=read(),a[i].v=read();
	for(int i=1;i<=k;i++)p[i]=read();sort(p+1,p+k+1);p[0]=0,p[k+1]=s;
	for(int i=k+1;i>=1;i--)p[i]=p[i]-p[i-1];k++;sort(p+1,p+k+1);
	for(int i=1;i<=k+1;i++)sum[i]=sum[i-1]+p[i];sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].v<p[k])break;	
		int pos=upper_bound(p+1,p+k+1,a[i].v/2)-p;
		int res=0;
		res+=(sum[pos-1]);
		//cout<<pos<<" "<<res<<endl;
		res+=3*(sum[k]-sum[pos-1]);
		res-=(k-pos+1)*a[i].v;
		//cout<<res<<endl;
		if(res<=t)ans=min(ans,a[i].c);
	}
	if(ans>1e9)puts("-1");
	else cout<<ans<<endl;
	return 0;
}