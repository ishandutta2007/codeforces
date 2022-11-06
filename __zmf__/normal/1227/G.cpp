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
const int N=1009;
int n,res;
int ans[N][N];
struct point
{
	int id,val;
}a[N];
inline bool cmp(point xxx,point yyy)
{
	return xxx.val>yyy.val;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i].val=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=i+a[i].val-1;j++)
			ans[(j-1)%(n+1)+1][a[i].id]=1;
	}res=n;
	for(int i=1;i<=n;i++)
		if(ans[n+1][i]!=0){res++;break;}
	cout<<res<<endl;
	for(int i=1;i<=res;i++)
	{
		for(int j=1;j<=n;j++)printf("%d",ans[i][j]);
		puts("");
	}
	return 0;
}