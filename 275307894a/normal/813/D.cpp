#include <vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define l(x) x<<1
#define r(x) x<<1|1
#define re register
#define ll long long
#define db long double
#define N 20000
#define eps (1e-14)
#define mod 998244353
using namespace std;
int n,m,k,x,y,z,g[N+5],d[N+5],pre[N+5],S,T,now,ans,a[N+5];
struct yyy{int to,w,g,z;}tmp;
struct ljb{
	int head,h[N+5];yyy f[N+5<<5];
	inline void add(int x,int y,int z,int g){f[head]=(yyy){y,z,g,h[x]};h[x]=head++;}
}s;
queue<int> q;
I int bfs(){
	memset(d,-0x3f,sizeof(d));memset(g,0,sizeof(g));q.push(S);d[S]=0;g[S]=1e9;
	while(!q.empty()){
		now=q.front();q.pop();//printf("%d %d\n",d[now],now);
		for(int i=s.h[now];~i;i=tmp.z){
			tmp=s.f[i];if(!tmp.g||d[tmp.to]>=d[now]+tmp.w) continue;d[tmp.to]=d[now]+tmp.w;
			g[tmp.to]=min(g[now],tmp.g);q.push(tmp.to);pre[tmp.to]=i;
		}
	}
	return d[T]>0;
}
I void get(int x,int y,int z,int g){s.add(x,y,z,g);s.add(y,x,-z,0);}
int main(){
//	freopen("1.in","r",stdin);
	memset(s.h,-1,sizeof(s.h));re int i,j;scanf("%d",&n);T=4*n+1;S=4*n+2;get(S,0,0,2);for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
	    get(0,i,0,2e9),get(i+n,T,0,2e9),get(i,i+n,1,1),get(i+2*n,i,0,2e9),get(i+3*n,i,0,2e9);
		for(j=i+1;j<=n;j++) if(a[i]%7==a[j]%7){get(i+n,j+2*n,0,2e9),get(i+2*n,j+2*n,0,2e9);break;}
		for(j=i+1;j<=n;j++) if(a[j]==a[i]-1){ get(i+n,j+3*n,0,2e9);break;}
		for(j=i+1;j<=n;j++) if(a[j]==a[i]+1) {get(i+n,j+3*n,0,2e9);break;}
		for(j=i+1;j<=n;j++) if(a[i]==a[j]){ get(i+3*n,j+3*n,0,2e9);break;}
	}
	while(bfs()){
		ans+=g[T]*d[T];now=T;//printf("%d\n",ans);
		while(now^S)s.f[pre[now]].g-=g[T],s.f[pre[now]^1].g+=g[T],now=s.f[pre[now]^1].to;
	}
	printf("%d\n",ans);
}