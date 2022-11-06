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
int taxi,n,s,mid,L,R,sum;
struct point
{
	int l,r;
}a[N];
inline bool cmp(point xxx,point yyy)
{
	return xxx.l>yyy.l;
}
inline int check(int x)
{
	int res=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].r>=x)res+=max(0ll,x-a[i].l),cnt++;
		if(cnt==(n+1)/2)break;
	}
	if(cnt!=(n+1)/2)return 0;
	return res<=s-sum;
}
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		L=1e15,R=0;sum=0;
		n=read();s=read();
		for(int i=1;i<=n;i++)a[i].l=read(),a[i].r=read(),L=min(L,a[i].l),R=max(R,a[i].r),sum+=a[i].l;
		sort(a+1,a+n+1,cmp);
	//	cout<<s-sum<<endl;
		int ans=0;
		while(L<=R)
		{
			mid=(L+R)/2;
			if(check(mid))L=mid+1,ans=mid;
			else R=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}