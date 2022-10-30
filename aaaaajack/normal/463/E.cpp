#include<cstdio>
#include<vector>
#include<cstring>
#define M 2000100
#define N 100100
using namespace std;
bool visit[N];
vector<int> g[N],stk[M];
int lpf[M],prm[M],a[N],depth[N];
int ans[N];
int pcnt=0;
void DFS(int x,int now_d){
	visit[x]=true;
	depth[x]=now_d;
	vector<int> vpf;
	int tmp=a[x],f,i;
	while(tmp>1){
		f=lpf[tmp];
		vpf.push_back(f);
		while(tmp%f==0) tmp/=f;
	}
	for(i=0;i<vpf.size();i++){
		if(!stk[vpf[i]].empty()){
			if(ans[x]==-1||depth[stk[vpf[i]].back()]>depth[ans[x]]){
				ans[x]=stk[vpf[i]].back();
			}
		}
		stk[vpf[i]].push_back(x);
	}
	for(i=0;i<g[x].size();i++){
		if(visit[g[x][i]]) continue;
		DFS(g[x][i],now_d+1);
	}
	for(i=0;i<vpf.size();i++){
		stk[vpf[i]].pop_back();
	}
}
void build(){
	memset(ans,-1,sizeof(ans));
	memset(visit,0,sizeof(visit));
	DFS(1,1);
}
int main(){
	int i,j;
	for(i=2;i<M;i++){
		if(!lpf[i]){
			prm[pcnt++]=i;
			lpf[i]=i;
		}
		for(j=0;j<pcnt&&prm[j]*i<M;j++){
			lpf[prm[j]*i]=prm[j];
			if(i%prm[j]==0) break;
		}
	}
	int n,q,x,y,t,v,w;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	build();
	while(q--){
		scanf("%d%d",&t,&v);
		if(t==1) printf("%d\n",ans[v]);
		else{
			scanf("%d",&w);
			a[v]=w;
			build();
		}
	}
	return 0;
}