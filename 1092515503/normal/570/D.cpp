#include<bits/stdc++.h>
using namespace std;
int n,m,tot,dep[500100],l[500100],r[500100];
vector<int>v[500100];
vector<pair<int,int> >u[500100];
char s[500100];
void dfs(int x){
	l[x]=++tot;
	u[dep[x]].push_back(make_pair(tot,u[dep[x]].back().second^(1<<(s[x]-'a'))));
	for(auto y:v[x])dep[y]=dep[x]+1,dfs(y);
	r[x]=tot;
}
bool query(int x,int d){
	int L=lower_bound(u[d].begin(),u[d].end(),make_pair(l[x],0))-u[d].begin()-1,R=upper_bound(u[d].begin(),u[d].end(),make_pair(r[x],0x3f3f3f3f))-u[d].begin()-1;
	return __builtin_popcount(u[d][L].second^u[d][R].second)<=1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2,x;i<=n;i++)scanf("%d",&x),v[x].push_back(i);
	for(int i=1;i<=n;i++)u[i].push_back(make_pair(0,0));
	scanf("%s",s+1);
	dep[1]=1,dfs(1);
//	for(int i=0;i<=2;i++){for(auto j:u[i])printf("%d ",j);puts("");}
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),puts(query(x,y)?"Yes":"No");
	return 0;
}