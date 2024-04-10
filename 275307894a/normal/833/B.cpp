#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,now,last,dp[2][100039],q[100039],head,tail,las[100039],a[100039],gs[100039];
int f[400039],g[400039];
inline void push(int now){
	f[now<<1]+=g[now];f[now<<1|1]+=g[now];
	g[now<<1]+=g[now];g[now<<1|1]+=g[now];
	g[now]=0;
}
inline void get(int x,int y,int z,int l,int r,int now){
	if(x<=l&&r<=y){f[now]+=z;g[now]+=z;return;}
	int m=l+r>>1;
	if(g[now])push(now);
	if(x<=m) get(x,y,z,l,m,now<<1);
	if(y>m) get(x,y,z,m+1,r,now<<1|1);
	f[now]=max(f[now<<1],f[now<<1|1]);
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now];
	int m=l+r>>1,fs1=0,fs2=0;
	if(g[now])push(now);
	if(x<=m)  fs1=find(x,y,l,m,now<<1);
	if(y>m) fs2=find(x,y,m+1,r,now<<1|1);
	return max(fs1,fs2);
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++) gs[i]=las[a[i]],las[a[i]]=i;
	for(i=1;i<=m;i++){
		now=i&1;last=now^1;
		head=tail=0;
		memset(f,0,sizeof(f));memset(g,0,sizeof(g));
		for(j=1;j<=n;j++){
			get(j-1,j-1,dp[last][j-1],0,n,1);
			get(gs[j],j-1,1,0,n,1);
			dp[now][j]=find(0,j-1,0,n,1);
			//printf("%d ",dp[now][j]);
		}
		//printf("\n");
	}
	printf("%d\n",dp[m&1][n]);
}