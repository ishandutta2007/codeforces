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
long long n,q[200009],k,p[200009],vis[200009],res=0;
signed main()
{
	n=read();
	for(int i=1;i<n;i++)q[i]=read();
	for(int i=1;i<n;i++)q[i]=q[i-1]+q[i],res=min(res,q[i]);
	p[1]=1-res;
	for(int i=2;i<=n;i++)p[i]=p[1]+q[i-1];
//	cout<<p[2]<<" "<<p[3]<<endl;
	for(int i=1;i<=n;i++)
	{
		if(p[i]<=0||p[i]>n)
		{
			puts("-1");return 0;
		}
		if(vis[p[i]])
		{
			puts("-1");return 0;
		}
		vis[p[i]]=1;
	}
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	return 0;
}
//cmll->zmf->zzm->dx->fyy->cmll