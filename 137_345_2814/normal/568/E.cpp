#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define N 105000
int n,m,v[N],v2[N],dp[N],f[N],f2[N],ct,las=1e9+100;
int ins(int x)
{
	if(x>f[ct]){f[++ct]=x;return ct;}
	int t=lower_bound(f+1,f+ct+1,x)-f;
	if(f[t-1]==x)t--;
	f[t]=x;return t;
}
void doit()
{
	int lb=1;
	for(int i=1;i<=ct;i++)
	{
		while(lb<=m&&v2[lb]<=f[i-1])lb++;
		if(lb<=m&&v2[lb]<f[i])f2[i]=v2[lb];else f2[i]=f[i];
	}
	while(lb<=m&&v2[lb]<=f[ct])lb++;
	for(int i=1;i<=ct;i++)f[i]=f2[i];
	if(lb<=m)f[++ct]=v2[lb];
}
multiset<int> fu;
set<int> tp[N];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	scanf("%d",&m);for(int i=1;i<=m;i++)scanf("%d",&v2[i]),fu.insert(v2[i]);
	sort(v2+1,v2+m+1);
	for(int i=1;i<=n;i++)if(v[i]==-1)doit();else dp[i]=ins(v[i]);
	for(int i=n;i>=1;i--)if(dp[i])tp[dp[i]].insert(i);
	int st=-1;
	if(tp[ct].size())st=*tp[ct].begin();
	else for(int i=1;i<=n;i++)if(v[i]==-1)st=i;
	for(int i=ct;i>=1;i--)
	{
		if(v[st]==-1)v[st]=*(--fu.lower_bound(las)),fu.erase(fu.find(v[st]));
		las=v[st];
		int tp2=-1;
		while(!tp[i-1].empty())
		{
			int s=*tp[i-1].begin();
			if(s<st&&v[s]<las)tp2=s;
			tp[i-1].erase(s);
		}
		if(tp2!=-1)st=tp2;
		else for(int j=st-1;j>=1;j--)if(v[j]==-1){st=j;break;}
	}
	for(int i=1;i<=n;i++)if(v[i]==-1)v[i]=*fu.begin(),fu.erase(fu.find(v[i]));
	for(int i=1;i<=n;i++)printf("%d ",v[i]);
}