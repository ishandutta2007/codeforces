#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 300300
using namespace std;
int N;
int par[MAXN];
long long cost[MAXN];
long long evenans[MAXN];
long long oddans[MAXN];
vector<int> connexion[MAXN];
long long evendfs(int);
long long oddfs(int pl)
{
	if(oddans[pl]!=-1LL) return oddans[pl];
	oddans[pl]=0LL;
	for(int i=0;i<connexion[pl].size();i++)
		oddans[pl]=max(oddans[pl],oddfs(connexion[pl][i])); 
	int oddcount=0;
	long long sum=0;
	long long mindiff=99887766554433211LL;
	for(int i=0;i<connexion[pl].size();i++)
	{
		long long ov=oddfs(connexion[pl][i]);
		long long ev=evendfs(connexion[pl][i]);
		sum+=max(ov,ev);
		mindiff=min(mindiff,abs(ov-ev));
		if(ov>ev) oddcount++;
	}
	if(oddcount%2==1)
	{
		oddans[pl]=max(oddans[pl],sum);
		oddans[pl]=max(oddans[pl],sum-mindiff+cost[pl]);
	}
	else
		oddans[pl]=max(oddans[pl],sum+cost[pl]);
	return oddans[pl];
}
long long evendfs(int pl)
{
	if(evenans[pl]!=-1LL) return evenans[pl];
	evenans[pl]=0LL;
	for(int i=0;i<connexion[pl].size();i++)
		evenans[pl]=max(evenans[pl],evendfs(connexion[pl][i]));
	int oddcount=0;
	long long sum=0;
	long long mindiff=99887766554433211LL;
	for(int i=0;i<connexion[pl].size();i++)
	{
		long long ov=oddfs(connexion[pl][i]);
		long long ev=evendfs(connexion[pl][i]);
		sum+=max(ov,ev);
		mindiff=min(mindiff,abs(ov-ev));
		if(ov>ev) oddcount++;
	}
	if(oddcount%2==0)
		evenans[pl]=max(evenans[pl],sum);
	else
		evenans[pl]=max(evenans[pl],sum-mindiff);
	return evenans[pl];
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%I64d",par+i,cost+i);
		par[i]--;
		if(par[i]!=-2) connexion[par[i]].push_back(i);
		evenans[i]=-1LL;
		oddans[i]=-1LL;
	}
	oddfs(0);
	evendfs(0);
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		ans=max(ans,evenans[i]);
		ans=max(ans,oddans[i]);
	}
	printf("%I64d",ans);
	return 0;
}