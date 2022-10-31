#include<cstdio>
#include<vector>
#include<cstring>
#define N 100100
using namespace std;
vector<int> ava[N],real[N],rev[N];
vector<int> ans;
int par[N];
bool visit[N]={};
int cnt[N]={},used[N]={};
bool check_par(int x){
	visit[x]=true;
	bool flag=false;
	if(par[x]) flag=true;
	for(int i=0;i<ava[x].size();i++){
		if(visit[ava[x][i]]) continue;
		if(check_par(ava[x][i])) flag=true;
	}
	return flag;
}
int add_edge(int x){
	visit[x]=true;
	int lack;
	for(int i=0;i<ava[x].size();i++){
		if(visit[ava[x][i]]) continue;
		if(par[ava[x][i]]) lack=2;
		else lack=0;
		lack-=add_edge(ava[x][i]);
		lack%=4;
		if(lack<=0) lack+=4;
		for(int j=0;j<lack;j++){
			rev[x].push_back(real[ava[x][i]].size());
			rev[ava[x][i]].push_back(real[x].size());
			real[x].push_back(ava[x][i]);
			real[ava[x][i]].push_back(x);
			cnt[x]++;
		}
	}
	return cnt[x];
}
void trav(int x){
	bool flag=false;
	for(int i=used[x];i<real[x].size();i=used[x]){
		used[x]=i+1;
		if(used[real[x][i]]<=rev[x][i]){
			flag=true;
			trav(real[x][i]);
			ans.push_back(x);
		}
	}
	if(!flag) ans.push_back(x);
}
int main(){
	int n,m,x,y,i,j,st=-1,root;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		ava[x].push_back(y);
		ava[y].push_back(x);
	}
	for(i=1;i<=n;i++) scanf("%d",&par[i]);
	for(i=1;i<=n;i++){
		if(visit[i]) continue;
		if(check_par(i)){
			if(st==-1) st=i;
			else st=-2;
		}
	}
	if(st==-2) puts("-1");
	else if(st==-1) puts("0");
	else{
		memset(visit,0,sizeof(visit));
		root=add_edge(st);
		if(root&1) puts("-1");
		else{
			trav(st);
			if(root%4/2==par[st]){
				ans.pop_back();
			}
		}
		printf("%d\n",ans.size());
		for(i=0;i<ans.size();i++){
			if(i) printf(" %d",ans[i]);
			else printf("%d",ans[i]);
		}
		puts("");
	}
	return 0;
}