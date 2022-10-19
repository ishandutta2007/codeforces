#include<cstdio>
#define l(x) f[x].l
#define r(x) f[x].r
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,b[500039],dp[500039],a[500039],cnt,root,ans,tot;
struct tree{int l,r,f;}f[20000039];
inline void get(int x,int y,int l,int r,int &now){
	if(!now) now=++cnt;
	if(l==r) {f[now].f=y;return;}
	int m=l+r>>1;
	if(x<=m) get(x,y,l,m,l(now));
	else get(x,y,m+1,r,r(now));
	f[now].f=max(f[l(now)].f,f[r(now)].f);
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y)return f[now].f;
	int m=l+r>>1,fs1=0,fs2=0;
	if(x<=m) fs1=find(x,y,l,m,l(now));
	if(y>m) fs2=find(x,y,m+1,r,r(now));
	return max(fs1,fs2);
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),a[i]-=i;
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	a[0]=-1e9;b[m+1]=n+1;a[n+1]=1e9;
	for(i=1;i<=m+1;i++){
		get(a[b[i-1]],0,-1e9,1e9,root);dp[b[i-1]]=0;
		for(j=b[i-1]+1;j<=b[i];j++){
			if(a[j]>=a[b[i-1]])dp[j]=find(-1e9,a[j],-1e9,1e9,root)+1,get(a[j],dp[j],-1e9,1e9,root);
		}  
		tot=-1e9;
		for(j=b[i-1];j<=b[i];j++)if(a[j]<=a[b[i]]&&a[j]>=a[b[i-1]]) tot=max(tot,dp[j]);
		if(tot==-1e9){printf("-1\n");return 0;}
		ans+=tot;
		for(j=b[i-1]+1;j<=b[i];j++) get(a[j],0,-1e9,1e9,root);
	}
	printf("%d\n",n-ans+1);
}