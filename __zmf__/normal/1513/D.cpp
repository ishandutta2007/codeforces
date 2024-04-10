//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,p;
int a[200009];
long long ans,now;
int vis[200009];
struct point
{
	int x,pos;
}k[200009];
inline bool cmp(point xxx,point yyy)
{
	return xxx.x<yyy.x;
}
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		ans=0;
		n=read(),p=read();now=n-1;
		for(int i=1;i<=n;i++)a[i]=read(),k[i].x=a[i],k[i].pos=i,vis[i]=0;
		sort(k+1,k+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(vis[k[i].pos]!=0)continue;
			if(k[i].x>=p)break; 
			int l=k[i].pos,r=k[i].pos;
			while(a[l]%k[i].x==0&&l>=1)
			{
				if(vis[l]==1)
				{
					l--;break;
				}
				l--;
				
			}
			while(a[r]%k[i].x==0&&r<=n)
			{
				if(vis[r]==1)
				{
					r++;break;
				}
				r++;
			}
			l++,r--;
			for(int j=l;j<r;j++)vis[j]++,vis[j+1]++;
		//	cout<<l<<" "<<r<<endl;
			ans=ans+(r-l)*k[i].x;now=now-(r-l);
		}
		ans=ans+now*p;
		printf("%lld\n",ans);
	}
	return 0;
}