#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#define sec(x) (x)*(x)
#define beg(x) cur=s.h[x]
#define end ~cur
#define go cur=tmp.z
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;
int n,m,k,x[839],y[839],z,flags,g[839],flag[839],id[839],pre[839],now,st,t,tot,cur;
double ans,d[839];
struct yyy{int to;float w;int g,z;}tmp;
struct ljb{
	int head,h[839];
	yyy f[500039];
	inline void add(int x,int y,float z,int g){
		f[head]=(yyy){y,z,g,h[x]};
		h[x]=head++;
	}
}s;
inline void get(int x,int y,float z,int g){s.add(x,y,z,g);s.add(y,x,-z,0);}
queue<int> q;
inline int bfs(){
	while(!q.empty()) q.pop();flags=0;
	for(int i=st;i<=t;i++) flag[i]=0,d[i]=1e8,g[i]=1e9;
	d[st]=0;q.push(st);
	while(!q.empty()){
		now=q.front();q.pop();flag[now]=0;flags|=(now==t?1:0);
		for(beg(now);end;go){
			tmp=s.f[cur];
			if(tmp.g&&d[tmp.to]>d[now]+tmp.w){
				d[tmp.to]=d[now]+tmp.w;pre[tmp.to]=cur;
				if(!flag[tmp.to]) q.push(tmp.to),flag[tmp.to]=1;
				g[tmp.to]=min(g[now],tmp.g);
			}
		}
	}
	return flags;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;memset(s.h,-1,sizeof(s.h));
	scanf("%d",&n);t=2*n+1;
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),get(st,i+n,0,1),id[i]=s.head-2,get(i,t,0,2);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) if(y[i]>y[j]) get(j+n,i,sqrt(sec(x[i]-x[j])+sec(y[i]-y[j])),1);
	}
	while(bfs()){
		ans+=d[t]*g[t];now=t;
		while(now!=st){
			s.f[pre[now]].g-=g[t];s.f[pre[now]^1].g+=g[t];
			now=s.f[pre[now]^1].to;
		}
	} 
	for(i=1;i<=n;i++) tot+=s.f[id[i]].g;
	if(tot>1) printf("-1\n");
	else printf("%.10f\n",ans);
}