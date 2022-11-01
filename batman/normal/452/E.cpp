#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)601*1000)
#define MOD ((ll)1e9+7)

ll n=1,m=N,ans[N],dp[N][3];
ll lst,nex[N][27],link[N],len[N];
vector <ll> e[N];

void add(ll c,ll id)
{
	ll x=lst;lst=n++;
	len[lst]=len[x]+1;dp[lst][id]++;
	while(x!=-1 && nex[x][c]==-1)nex[x][c]=lst,x=link[x];
	if(x==-1)return ;
	ll y=nex[x][c];
	if(len[x]+1==len[y]){link[lst]=y;return ;}
	ll z=n++;len[z]=len[x]+1;link[z]=link[y];
	for(int i=0;i<27;i++)nex[z][i]=nex[y][i];
	link[lst]=link[y]=z;
	while(x!=-1 && nex[x][c]==y)nex[x][c]=z,x=link[x];
}

void dfs(ll x)
{
	for(auto u:e[x])
	{
		dfs(u);
		for(int i=0;i<3;i++)dp[x][i]+=dp[u][i];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	memset(nex,-1,sizeof nex);
	link[0]=-1;
	for(int i=0;i<3;i++)
	{
		string s;
		cin>>s;m=min(m,(ll)s.size());
		for(int j=0;j<s.size();j++)
			add(s[j]-'a',i);
		add(26,0);
	}
	for(int i=1;i<n;i++)e[link[i]].push_back(i);
	dfs(0);
	for(int i=1;i<n;i++)
	{
		int ex=(1LL*dp[i][0]*dp[i][1]*dp[i][2])%MOD;
		ans[len[link[i]]+1]+=ex;ans[len[link[i]]+1]%=MOD;
		ans[len[i]+1]+=MOD-ex;ans[len[i]+1]%=MOD;
	}
	for(int i=1;i<=m;i++)
	{
		ans[i]+=ans[i-1];ans[i]%=MOD;
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}