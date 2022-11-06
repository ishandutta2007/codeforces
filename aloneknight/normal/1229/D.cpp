#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
#define B bitset<120>
const int P=1e9+7;
int n,k,f[120][120],g[120][6],h[6][6][6][6][6];
vector<pair<pair<B,int>,vector<int>>>V[2];
B zr,b;vector<int>t;
void dfs(int id){for(auto x:t)if(!b[f[id][x]]){b[f[id][x]]=1;dfs(f[id][x]);}}
B sol(vector<int>v,int g){v.push_back(g);t=v;b=zr;dfs(0);return b;}
int main()
{
	scanf("%d%d",&n,&k);zr[0]=1;ll ans=0;
	int p[6]={0,1,2,3,4,5};
	for(int i=0;i<120;i++)
	{
		for(int j=1;j<=5;j++)g[i][j]=p[j];
		h[p[1]][p[2]][p[3]][p[4]][p[5]]=i;
		next_permutation(p+1,p+6);
	}
	for(int i=0;i<120;i++)for(int j=0;j<120;j++)f[i][j]=h[g[j][g[i][1]]][g[j][g[i][2]]][g[j][g[i][3]]][g[j][g[i][4]]][g[j][g[i][5]]];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)scanf("%d",&p[j]);
		for(int j=k+1;j<=5;j++)p[j]=j;
		int id=h[p[1]][p[2]][p[3]][p[4]][p[5]],nw=i&1,pr=nw^1;
		vector<int>ff;V[pr].push_back({{zr,1},ff});V[nw].clear();
		for(auto t:V[pr])
		{
			B x=sol(t.Y,id);if(x!=t.X.X)t.X.X=x,t.Y.push_back(id);
			if(!V[nw].empty()&&V[nw].back().X.X==x)V[nw].back().X.Y+=t.X.Y;else V[nw].push_back(t);
		}
		for(auto t:V[nw])ans+=t.X.X.count()*t.X.Y;
	}
	printf("%lld\n",ans);
	return 0;
}