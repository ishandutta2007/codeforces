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
const int N=3e5+9,INF=1e13;
int n,x1,x2,flag,pos1,pos2;
struct point
{
	int c,pos;
}a[N];
inline bool cmp(point xxx,point yyy)
{
	return xxx.c>yyy.c;
}
signed main()
{
	n=read(),x1=read(),x2=read();
	for(int i=1;i<=n;i++)a[i].c=read(),a[i].pos=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].c>=(x1+i-1)/i)
		{
			pos1=i;break;
		}
	}
	for(int i=pos1+1;i<=n;i++)
	{
		if(a[i].c>=(x2+i-pos1-1)/(i-pos1))
		{
			pos2=i;break;
		}
	}
	if(pos1&&pos2)
	{
		cout<<"Yes"<<endl;
		cout<<pos1<<" "<<pos2-pos1<<endl;
		for(int i=1;i<=pos1;i++)printf("%d ",a[i].pos);puts("");
		for(int i=pos1+1;i<=pos2;i++)printf("%d ",a[i].pos);puts("");
		return 0;
	}
	pos1=pos2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].c>=(x2+i-1)/i)
		{
			pos1=i;break;
		}
	}
	for(int i=pos1+1;i<=n;i++)
	{
		if(a[i].c>=(x1+i-pos1-1)/(i-pos1))
		{
			pos2=i;break;
		}
	}
	if(pos1&&pos2)
	{
		cout<<"Yes"<<endl;
		cout<<pos2-pos1<<" "<<pos1<<endl;
		for(int i=pos1+1;i<=pos2;i++)printf("%d ",a[i].pos);puts("");
		for(int i=1;i<=pos1;i++)printf("%d ",a[i].pos);puts("");
		return 0;
	}
	puts("No");
	return 0;
}