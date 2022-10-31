#include<cstdio>
#include<vector>
#include<algorithm>
#define N 500100
using namespace std;
int in[N],out[N],cnt=1;
char s[N];
vector<int> g[N];
vector<int> pos[N],num[N];
void DFS(int u,int d){
	in[u]=cnt++;
	pos[d].push_back(in[u]);
	num[d].push_back(num[d].back()^(1<<s[u]-'a'));
	for(int i=0;i<g[u].size();i++){
		DFS(g[u][i],d+1);
	}
	out[u]=cnt;
}
inline int pop_count(int x){
	int res=0;
	while(x) res+=x&1,x>>=1;
	return res;
}
int main(){
	int n,m,x,d,st,ed;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		g[x].push_back(i);
	}
	for(int i=1;i<=n;i++){
		pos[i].push_back(0);
		num[i].push_back(0);
	}
	scanf("%s",s+1);
	DFS(1,1);
	while(m--){
		scanf("%d%d",&x,&d);
		ed=lower_bound(pos[d].begin(),pos[d].end(),out[x])-pos[d].begin()-1;
		st=lower_bound(pos[d].begin(),pos[d].end(),in[x])-pos[d].begin()-1;
		if(pop_count(num[d][ed]^num[d][st])<=1) puts("Yes");
		else puts("No");
	}
	return 0;
}