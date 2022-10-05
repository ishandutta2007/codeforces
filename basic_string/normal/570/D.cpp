#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
basic_string<int>g[N];
vector<pair<int,int>>o[N];
char s[N];
int ans[N],c[N];
void dfs(int x,int d){
	for(auto i:o[x])ans[i.second]^=c[i.first];
	c[d]^=1<<s[x]-'a';
	for(int i:g[x])dfs(i,d+1);
	for(auto i:o[x])ans[i.second]^=c[i.first];
}
int main(){
	int n,q,i,j,k;
	scanf("%d%d",&n,&q);
	for(i=2;i<=n;++i)scanf("%d",&j),g[j]+=i;
	scanf("%s",s+1);
	for(i=1;i<=q;++i)scanf("%d%d",&j,&k),o[j].push_back({k,i});
	dfs(1,1);
	for(i=1;i<=q;++i)j=ans[i],puts((j&-j)==j?"Yes":"No");
	return 0;
}