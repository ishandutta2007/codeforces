#include<bits/stdc++.h>
using namespace std;
int x[200005],l[200005],fa[23][200005];
long long zz[23][200005];
int main()
{
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&l[i]);
	stack<int>s;
	for(int i=n;i>=1;i--)
	{
		while(s.size()&&x[s.top()]+l[s.top()]<x[i]+l[i])s.pop();
		if(!s.size())fa[0][i]=0,zz[0][i]=0;
		else fa[0][i]=s.top(),zz[0][i]=max(0,x[s.top()]-(x[i]+l[i]));
		s.push(i);
	}
	for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)
	{
		fa[i][j]=fa[i-1][fa[i-1][j]];
		zz[i][j]=zz[i-1][j]+zz[i-1][fa[i-1][j]];
	}
	cin>>q;
	while(q--)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		long long ans=0;
		for(int i=20;i>=0;i--)if(fa[i][L]&&fa[i][L]<=R)
			ans+=zz[i][L],L=fa[i][L];
		ans+=max(0,x[R]-(x[L]+l[L]));
		printf("%lld\n",ans);
	}
	return 0;
}