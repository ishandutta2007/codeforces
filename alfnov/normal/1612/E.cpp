#include<bits/stdc++.h>
using namespace std;
vector<int>g[200005];
int aa[200005],bb[200005];
int x,y,w;
int ns[200005];
pair<int,int>pi[200005];
int main()
{
	int n,a=200000;
	cin>>n;
	for(int i=1;i<=a;i++)pi[i].second=i;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		aa[x]+=y;
		pi[x].first+=y;
	}
	sort(aa+1,aa+a+1,greater<int>());
	int he=0;
	for(int i=1;i<=20;i++)he+=aa[i];
	x=0,y=1,w=1;
	for(int i=21;i<=a;i++)
	{
		he+=aa[i];
		if(1ll*he*y>1ll*i*x)
		{
			x=he,y=i;
			w=i;
		}
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=a;j++)
		{
			bb[j]=0;
			for(int k=0;k<g[j].size();k++)
			{
				int cu=g[j][k];
				bb[j]+=min(i,cu);
			}
		}
		sort(bb+1,bb+a+1,greater<int>());
		int A=0;
		for(int j=1;j<=i;j++)A+=bb[j];
		if(1ll*A*y>1ll*i*x)
		{
			x=A,y=i;
			w=i;
		}
	}
	if(w>=21)
	{
		cout<<w<<endl;
		sort(pi+1,pi+a+1);
		for(int i=a-w+1;i<=a;i++)printf("%d ",pi[i].second);
	}else
	{
		cout<<w<<endl;
		for(int j=1;j<=a;j++)
		{
			pi[j].second=j,pi[j].first=0;
			for(int k=0;k<g[j].size();k++)
			{
				int cu=g[j][k];
				pi[j].first+=min(w,cu);
			}
		}
		sort(pi+1,pi+a+1);
		for(int i=a-w+1;i<=a;i++)printf("%d ",pi[i].second);
	}
	return 0;
}