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
const int N=(1<<20)+9;
int n,a[N],m,tmp[N];
int cnt[29][2];//0 ->  1-> 
inline void Merge(int l,int r,int x)
{
	if(l>=r)return ;
	int mid=(l+r)>>1;
	Merge(l,mid,x-1);Merge(mid+1,r,x-1);
	int i=l,j=mid+1,tot=0;
	while(i<=mid&&j<=r)
		if(a[i]<a[j])cnt[x][0]+=r-j+1,i++;
		else j++;
	i=l,j=mid+1,tot=0;
	while(i<=mid&&j<=r)
		if(a[i]<=a[j])tmp[++tot]=a[i],i++;
		else cnt[x][1]+=mid-i+1,tmp[++tot]=a[j],j++;
	while(i<=mid)tmp[++tot]=a[i++];
	while(j<=r)tmp[++tot]=a[j++];
	for(int i=l;i<=r;i++)a[i]=tmp[i-l+1];
	return ;
} 
signed main()
{
	n=read();
	for(int i=1;i<=(1<<n);i++)a[i]=read();
	Merge(1,(1<<n),n);
	m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read();
	//	for(int j=1;j<=n;j++)cout<<cnt[j][0]<<" "<<cnt[j][1]<<endl;
		for(int j=0;j<=x;j++)swap(cnt[j][0],cnt[j][1]);
		int ans=0;
	//	for(int j=1;j<=n;j++)cout<<cnt[j][0]<<" "<<cnt[j][1]<<endl;
		for(int j=0;j<=n;j++)ans=ans+cnt[j][1];
		printf("%lld\n",ans);
	}
	return 0;
}