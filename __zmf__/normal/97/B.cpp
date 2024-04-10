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
const int N=1e4+9,M=4e5+9;
int n,cnt,top; 
struct point
{
	int x,y;
}a[N],ans[M],stac[M];
inline void work(int l,int r)
{
	if(l==r)return ;
	int mid=(l+r)/2;
	work(l,mid);work(mid+1,r);
	for(int i=l;i<=r;i++)
		ans[++cnt].x=a[mid].x,ans[cnt].y=a[i].y;
	return ;
}
inline bool cmp(point xxx,point yyy)
{
	if(xxx.x!=yyy.x)return xxx.x<yyy.x;
	else return xxx.y<yyy.y;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].y=read(),ans[++cnt].x=a[i].x,ans[cnt].y=a[i].y;
	sort(a+1,a+n+1,cmp);
	work(1,n);
	sort(ans+1,ans+cnt+1,cmp);top=0;
	for(int i=1;i<=cnt;i++)
	{
		while(top>0&&ans[i].x==stac[top].x&&ans[i].y==stac[top].y)top--;
		stac[++top].x=ans[i].x,stac[top].y=ans[i].y;
	}
	cout<<top<<endl;
	for(int i=1;i<=top;i++)printf("%d %d\n",stac[i].x,stac[i].y);
	return 0;
}