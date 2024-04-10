#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
typedef int ar[N];
unordered_map<string,int>mp;
unordered_set<int>st[N];
ar a,d,mx,sz,sn,ans;
basic_string<int>g[N];
vector<pair<int,int>>o[N];
void dfs(int x){
	sz[x]=1,mx[x]=d[x];
	for(int i:g[x])if(d[i]=d[x]+1,dfs(i),sz[x]+=sz[i],mx[x]=max(mx[x],mx[i]),sz[i]>sz[sn[x]])sn[x]=i;
}
void ins(int x){
	st[d[x]].insert(a[x]);
	for(int i:g[x])ins(i);
}
void dp(int x,bool b){
	for(int i:g[x])if(i!=sn[x])dp(i,1);
	if(sn[x])dp(sn[x],0);
	st[d[x]].insert(a[x]);
	for(int i:g[x])if(i!=sn[x])ins(i);
	for(auto i:o[x])ans[i.second]=st[min(N-1,d[x]+i.first)].size();
	if(b)for(int i=d[x];i<=mx[x];++i)st[i]={};
}
int main(){
	string s;
	int n,q,id=0,i,j,k;
	ios::sync_with_stdio(0),cin>>n,++n;
	for(i=2;i<=n;++i){
		cin>>s>>j;
		if(!mp[s])mp[s]=++id;
		a[i]=mp[s],g[j+1]+=i;
	}
	cin>>q;
	for(i=1;i<=q;++i)cin>>j>>k,o[j+1].push_back({k,i});
	dfs(1),dp(1,0);
	for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}