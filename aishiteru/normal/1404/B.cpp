#include<stdio.h>
#include<vector>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int T,n,fl,mxd,id,a,b,da,db;
std::vector<int> g[N];
il void dfs(ct x,ct fa,ct d){
	if(d>mxd) mxd=d,id=x;
	for(const int &j : g[x]) if(j^fa) dfs(j,x,d+1);
}
il void dfs_ck(ct x,ct fa,ct dis){
	//printf("x=%d dis=%d\n",x,dis);
	if(x==b) return fl=(dis<=da),void();
	for(const int &j : g[x]) if(j^fa) dfs_ck(j,x,dis+1);
}
int main(){
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for(it i=1;i<=n;++i) g[i].clear();
		for(it i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u); 
		dfs_ck(a,0,0);
		if(fl){puts("Alice");continue;}
		mxd=0,dfs(1,0,1),mxd=-1,dfs(id,0,0);
	//	printf("%d\n",mxd);
		if(mxd<=2*da||2*da>=db){puts("Alice");continue;}
		puts("Bob");
	}
	return 0;
}