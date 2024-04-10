#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num;LL ans=0;
int a[100002],c[100002],id[100002],mx[100002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
inline int max(int x,int y)
{
	return x>y? x:y;
}
inline int binary_search(int l,int r,int x)
{
	int mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(a[id[mid]]>x)r=mid-1;
		else l=mid+1;
	}
	return r;
}
int main()
{
	read(n);for(int i=1;i<=n;++i)read(a[i]),read(c[i]),ans+=c[i],c[i]+=a[i],id[i]=i;
	sort(id+1,id+n+1,cmp);for(int i=1;i<=n;++i)mx[i]=max(mx[i-1],c[id[i]]);
	for(int i=1,j;i<n;i=j)if((j=binary_search(i+1,n,mx[i]))==i)ans+=a[id[++j]]-mx[i];
	return 0&printf("%lld",ans);
}