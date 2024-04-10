//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e5+9;
int ans,l,r,n,s1,s2,a[N];
inline bool check(int x)
{
	int L=-1e9,R=1e9;
	for(int i=n;i>=1;i--)
	{
		if(L<=a[i]&&a[i]<=R)L=a[i]-x,R=a[i]+x;
		else L=max(L,a[i]-x),R=min(R,a[i]+x);
	}
	if(L<=s1&&s1<=R)return 1;
	if(L<=s2&&s2<=R)return 1;
	return 0;
}
int main()
{
	n=read();s1=read(),s2=read();
	for(int i=1;i<=n;i++)a[i]=read();
	l=ans=abs(s1-s2);r=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}