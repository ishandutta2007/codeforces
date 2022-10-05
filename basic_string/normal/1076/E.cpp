#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3;
basic_string<int>g[N];
vector<pair<int,int>>q[N];
using ll=long long;
ll s[N],a[N];
void dfs(int x,int y,int d,ll o){
	for(auto i:q[x])o+=i.second,a[min(N-1,d+i.first)]+=i.second;
	s[x]=o;
	for(int i:g[x])if(i!=y)dfs(i,x,d+1,o-a[d]);
	for(auto i:q[x])a[min(N-1,d+i.first)]-=i.second;
}
int main(){
	int n,m,i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j;
	scanf("%d",&m);
	while(m--)scanf("%d%d%d",&i,&j,&k),q[i].push_back({j,k});
	dfs(1,0,0,0);
	for(i=1;i<=n;++i)printf("%lld ",s[i]);
	return 0;
}