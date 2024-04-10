#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
typedef int ar[N];
vector<pair<int,int>>u[N],v[N];
basic_string<int>g[N];
int tp,id;
ar a,st,d,e,ct,l,r,ans;
void dfs(int x){
	st[tp++]=x,l[x]=id++,e[id]=d[x];
	for(auto i:u[x])if(d[x]>i.first)a[i.second]=st[d[x]-i.first];
	for(int i:g[x])d[i]=d[x]+1,dfs(i);
	--tp,r[x]=id;
}
int main(){
	int n,q,i,j,k;
	scanf("%d",&n),++n;
	for(i=2;i<=n;++i)scanf("%d",&j),++j,g[j]+=i;
	scanf("%d",&q);
	for(i=1;i<=q;++i)scanf("%d%d",&j,&k),++j,u[j].push_back({k,i});
	dfs(1);
	for(i=1;i<=n;++i)for(auto j:u[i])if(k=j.second,a[k])v[l[a[k]]].push_back({d[i],-k}),v[r[a[k]]].push_back({d[i],k});else ans[k]=1;
	for(i=1;i<=n;++i){
		++ct[e[i]];
		for(auto j:v[i])if((k=j.second)<0)ans[-k]-=ct[j.first];else ans[k]+=ct[j.first];
	}
	for(i=1;i<=q;++i)printf("%d ",ans[i]-1);
	return 0;
}