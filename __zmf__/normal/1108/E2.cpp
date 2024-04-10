//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,m,a[100009],nowl,nowr,ans,maxn,L,R,cnt,res[100009];
struct point
{
	int l,r,id;
}p[309];
inline bool cmp(point xxx,point yyy)
{
	return xxx.l<yyy.l;
}
inline void add(int x)
{
	for(int j=p[x].l;j<=p[x].r;j++)a[j]--;
}
inline void del(int x)
{
	for(int j=p[x].l;j<=p[x].r;j++)a[j]++;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)p[i].l=read(),p[i].r=read(),p[i].id=i;
	sort(p+1,p+m+1,cmp);
	nowl=1,nowr=0;
	maxn=-1e9;ans=-1e9;
	for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
	for(int i=1;i<=n;i++)
	{
		bool flag=0;
		while(p[nowr+1].l<=i&&nowr<m)
		{
			add(++nowr);flag=1;
		}
		for(int j=1;j<=nowr;j++)
			if(p[j].r==i-1)
			{
				del(j);flag=1;
			}
		if(!flag)
		{
			if(maxn-a[i]>ans)
			{
				cnt=0;
				ans=max(ans,maxn-a[i]);
				for(int j=1;j<=m;j++)
					if(p[j].l<=i&&p[j].r>=i)
						res[++cnt]=p[j].id;
			}
			continue;
		}
		maxn=-1e9;
		for(int j=1;j<=n;j++)maxn=max(maxn,a[j]);
		//for(int j=;j<=n;j++)cout<<a[j]<<" ";
		if(maxn-a[i]>ans)
		{
			ans=max(ans,maxn-a[i]);
			cnt=0;
			for(int j=1;j<=m;j++)
				if(p[j].l<=i&&p[j].r>=i)
					res[++cnt]=p[j].id;
		}
	}
	cout<<ans<<endl;
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		printf("%d ",res[i]);
	return 0;
}