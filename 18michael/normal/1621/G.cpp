#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,las,ans,mx,Test_num;
int a[200002],id[200002],f[200002],g[200002],nx[200002];
vector<int> vec[200002];
inline void add(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
	if(x<=-mod)x+=mod;
}
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[200002];
	inline void clear()
	{
		for(int i=1;i<=n;++i)sum[i]=0;
	}
	inline void modify(int x,int d)
	{
		while(x<=n)add(sum[x],d),x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)add(res,sum[x]),x-=lowbit(x);
		return res;
	}
}S;
inline bool cmp(int x,int y)
{
	return a[x]==a[y]? (x>y):(a[x]<a[y]);
}
inline void solve()
{
	scanf("%d",&n),las=ans=mx=0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),id[i]=i,vec[i].clear();
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		if(a[id[i]]!=las)swap(a[id[i]],las);
		a[id[i]]=a[id[i-1]]+(a[id[i]]!=las);
	}
	for(int i=1;i<=n;++i)add(f[i]=S.query(a[i]-1),1),S.modify(a[i],f[i]);
	S.clear();
	for(int i=n;i;--i)add(g[i]=S.query(n-a[i]),1),S.modify(n-a[i]+1,g[i]),nx[id[i]]=(mx<id[i]? 0:mx),mx=max(mx,id[i]);
	for(int i=1;i<=n;++i)if(nx[i])ans=((LL)f[i]*g[i]+ans)%mod,vec[nx[i]].push_back(i);
	S.clear();
	for(int i=1;i<=n;++i)
	{
		vec[i].push_back(i);
		for(int j=0;j<vec[i].size();++j)add(g[j]=S.query(a[vec[i][j]]-1),(j+1<vec[i].size()? f[vec[i][j]]:0)),S.modify(a[vec[i][j]],g[j]);
		add(ans,-g[vec[i].size()-1]);
		for(int j=0;j<vec[i].size();++j)S.modify(a[vec[i][j]],-g[j]);
	}
	printf("%d\n",(ans+mod)%mod);
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}