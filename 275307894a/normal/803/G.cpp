#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define I inline
#define dis(x) ((x-1)%n+1)
#define ks(x) ((x-1)/n)
#define N 100039
using namespace std;
int n,m,k,op,x,y,z,a[N],lg[N],st[N][20],root;
struct tree{int l,r,f,sum;};
struct sgt{
	int cnt,l[N*100],r[N*100],f[N*100],sum[N*100];
	I int find(int x,int y){int now=lg[y-x+1];return min(st[x][now],st[y-(1<<now)+1][now]);}
	I int finds(int x,int y){
    	if(ks(x)<ks(y)&&(ks(x)<ks(y)-1||dis(x)<=dis(y)))return find(1,n);
    	else return ks(x)!=ks(y)?(min(find(dis(x),n),find(1,dis(y)))):find(dis(x),dis(y));
    }
	I void newnode(int &x){!x&&(x=++cnt);}
	I void push(int x,int y){sum[x]=f[x]=y;}
	I void pushdown(int x){sum[x]&&(newnode(l[x]),push(l[x],sum[x]),newnode(r[x]),push(r[x],sum[x]),sum[x]=0);}
	I void up(int x,int ls,int rs){int m=ls+rs>>1;f[x]=min(l[x]?f[l[x]]:finds(ls,m),r[x]?f[r[x]]:finds(m+1,rs));}
	I void get(int x,int y,int z,int &now,int ls=1,int rs=n*k){
		!now&&(now=++cnt);f[now]=finds(ls,rs);if(x<=ls&&rs<=y){f[now]=sum[now]=z;return;}pushdown(now);
		int m=ls+rs>>1;x<=m&&(get(x,y,z,l[now],ls,m),0);y>m&&(get(x,y,z,r[now],m+1,rs),0);up(now,ls,rs);
	}
	I int fds(int x,int y,int now,int ls=1,int rs=n*k){
		if(x<=ls&&rs<=y){/*printf("%d %d %d\n",ls,rs,now);*/return now?f[now]:finds(ls,rs);}int m=ls+rs>>1;pushdown(now);
		int fs1=(x<=m?fds(x,y,l[now],ls,m):2e9),fs2=(y>m?fds(x,y,r[now],m+1,rs):2e9);
		/*printf("%d %d\n",fs1,fs2);*/return min(fs1,fs2);
	}
}g;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;scanf("%d%d",&n,&k);
	for(i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=n;i;i--){
		for(st[i][0]=a[i],j=1;i+(1<<j)-1<=n;j++) st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&op,&x,&y);
		(op^2)?(scanf("%d",&z),g.get(x,y,z,root),0):(printf("%d\n",g.fds(x,y,root)));
	}
}