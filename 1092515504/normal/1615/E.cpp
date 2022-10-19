#include<bits/stdc++.h>
using namespace std;
int n,m,len[200100],son[200100],sum;
bool iss[200100];
vector<int>v[200100],u;
void dfs(int x,int fa){
	len[x]=1;
	for(auto y:v[x])if(y!=fa){
		dfs(y,x);
		if(len[x]<len[y]+1)len[x]=len[y]+1,son[x]=y;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<=n;i++)if(son[i])iss[son[i]]=true;
	for(int i=1;i<=n;i++)if(!iss[i])u.push_back(len[i]);
	sort(u.rbegin(),u.rend());
	if(u.size()<=m){
		long long mx=0;
		for(int i=u.size();i<=m;i++)mx=max(mx,1ll*i*(n-i));
		printf("%lld\n",mx);return 0;
	}
	for(int i=0;i<m;i++)sum+=u[i];
	long long mn=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<=n-sum;i++)mn=min(mn,1ll*(n-m-i)*(m-i));
	printf("%lld\n",mn);
	return 0;
}