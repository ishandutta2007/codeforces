#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=100005,M=1000000007;
int n,f[105][105][105][2],v[105],sa,sb,aa[105],i;
int dfs(int i,int a,int b,int x)
{
	if(i>n)
		return 0;
	if(f[i][a][b][x]!=-1)
		return f[i][a][b][x];
	int s=1<<30;
	if(aa[i]==0)
	{
		if(a)
			s=min(s,dfs(i+1,a-1,b,1)+(x==0)*(i!=1));
		if(b)
			s=min(s,dfs(i+1,a,b-1,0)+(x==1)*(i!=1));
	}
	else
		s=dfs(i+1,a,b,aa[i]&1)+((aa[i]&1)!=x)*(i!=1);
	return f[i][a][b][x]=s;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&aa[i]);
		v[aa[i]]=1;
	}
	for(i=1;i<=n;++i)
		if(!v[i])
			if(i&1)
				++sa;
			else
				++sb;
	memset(f,-1,sizeof(f));
	cout<<dfs(1,sa,sb,0);
}