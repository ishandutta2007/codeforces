#include<cstdio>
#include<vector>
using namespace std;
struct edge{
	int des;
	bool rep;
};
bool dfs(vector<vector<edge> >& g,int now,vector<int>& ans,bool nrep,int from){
	bool hrep=false;
	for(int i=0;i<g[now].size();i++){
		if(g[now][i].des==from) continue;
		if(dfs(g,g[now][i].des,ans,g[now][i].rep,now)) hrep=true;
	}
	if(!hrep&&nrep) ans.push_back(now);
	if(hrep||nrep) return true;
	return false;
}
		
int main(){
	edge temp;
	int n,i,x,y,r;
	scanf("%d",&n);
	vector<vector<edge> > g(n+1,vector<edge>());
	vector<int> ans;
	for(i=0;i<n-1;i++){
		scanf("%d%d%d",&x,&y,&r);
		if(r==1) temp.rep=false;
		else temp.rep=true;
		temp.des=x;
		g[y].push_back(temp);
		temp.des=y;
		g[x].push_back(temp);
	}
	dfs(g,1,ans,false,0);
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++){
		if(i==ans.size()-1) printf("%d\n",ans[i]);
		else printf("%d ",ans[i]);
	}
	return 0;
}