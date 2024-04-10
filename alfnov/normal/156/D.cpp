#include<bits/stdc++.h>
using namespace std;
int fa[100005],cnt[100005];
int findfather(int x)
{
	return x==fa[x]?x:fa[x]=findfather(fa[x]);
}
int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=findfather(x),fy=findfather(y);
		if(fx!=fy)fa[fx]=fy;
	}
	for(int i=1;i<=n;i++)cnt[findfather(i)]++;
	int k=0,ans=1;
	for(int i=1;i<=n;i++)if(i==fa[i])
	{
		ans=1ll*ans*cnt[i]%p;
		k++;
	}
	for(int i=1;i<=k-2;i++)ans=1ll*ans*n%p;
	if(k==1)ans=1%p;
	cout<<ans<<endl;
	return 0;
}