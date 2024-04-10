#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int a[300005],qu[300005],vi[300005],b[300005];
vector<int>g[300005];
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
int main()
{
	srand(time(0));
	srand(20090908+rand());
	int n=rd(),m=rd();
	for(int i=1;i<=n;i++)a[i]=rd(),g[a[i]].push_back(i);
	int B=0;
	for(int i=1;i<=n;i++)if(g[i].size()>1000)b[++B]=i;
	while(m--)
	{
		int l=rd(),r=rd(),k=rd();
		int ss=(r-l+1)/k,T=70,ans=INT_MAX,tt=0;
		for(int i=1;i<=B;i++)
		{
			int x=b[i];
			if(vi[x])continue;
			qu[++tt]=x,vi[x]=1;
			int R=lower_bound(g[x].begin(),g[x].end(),r+1)-g[x].begin();
			if(R<=ss||g[x][R-ss-1]<l)continue;
			ans=min(ans,x);
		}
		while(T--)
		{
			int x=a[rand()%(r-l+1)+l];
			if(vi[x])continue;
			qu[++tt]=x,vi[x]=1;
			int R=lower_bound(g[x].begin(),g[x].end(),r+1)-g[x].begin();
			if(R<=ss||g[x][R-ss-1]<l)continue;
			ans=min(ans,x);
		}
		for(int i=1;i<=tt;i++)vi[qu[i]]=0;
		if(ans>1e9)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}