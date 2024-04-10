#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define N 100100
#define inf 1023456789
using namespace std;
vector<int> g[N],inv[N];
int l[N],r[N],c[N],tl[2],tr[2];
inline void add(int u,int v,bool x){
	g[u].push_back(v);
	inv[u].push_back(x);
	g[v].push_back(u);
	inv[v].push_back(x);
}
bool col(int u,int x){
	if(c[u]!=-1) return c[u]==x;
	c[u]=x;
	tl[x]=max(tl[x],l[u]);
	tr[x]=min(tr[x],r[u]);
	for(int i=0;i<g[u].size();i++){
		if(!col(g[u][i],x^inv[u][i])) return false;
	}
	return true;
}
int main(){
	memset(c,-1,sizeof(c));
	bool wrong=false;
	int n,m,llim,rlim,lu,ru,x,y,ml,mr;
	scanf("%d%d",&llim,&rlim);
	tl[0]=tl[1]=ml=0;
	tr[0]=tr[1]=mr=inf;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		if(l[i]>=ml){
			lu=i;
			ml=l[i];
		}
		if(r[i]<=mr){
			ru=i;
			mr=r[i];
		}
	}
	while(m--){
		scanf("%d%d",&x,&y);
		add(x,y,1);
	}
	for(int i=1;i<=n;i++){
		if(l[i]>rlim-ml) add(i,lu,0);
		if(r[i]<llim-mr) add(i,ru,0);
	}
	for(int i=1;i<=n;i++){
		if(l[i]>mr){
			if(!col(i,1)) wrong=true;
		}
		if(r[i]<ml){
			if(!col(i,0)) wrong=true;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]==-1){
			if(!col(i,0)) wrong=true;
		}
	}
	if(tr[0]<tl[0] || tr[1]<tl[1] || tr[0]+tr[1]<llim || tl[0]+tl[1]>rlim ) wrong=true;
	if(wrong){
		puts("IMPOSSIBLE");
	}
	else{
		puts("POSSIBLE");
		if(llim>tl[0]+tl[1]){
			int add=llim-tl[0]-tl[1];
			if(add>tr[0]-tl[0]){
				tl[1]+=add-(tr[0]-tl[0]);
				tl[0]=tr[0];
			}
			else tl[0]+=add;
		}
		printf("%d %d\n",tl[0],tl[1]);
		for(int i=1;i<=n;i++) printf("%d",c[i]+1);
		puts("");
	}
	return 0;
}