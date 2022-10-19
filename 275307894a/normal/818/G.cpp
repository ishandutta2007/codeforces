#include<cstdio>
#include<queue>
#include<cstring>
#define beg(x) int cur=s.h[x]
#define end ~cur
#define go cur=tmp.z
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,g[10039],last[100039],flag[10039],d[10039],pre[10039],a[10039],st,t,fz[13],now,ans;
struct yyy{int to,w,g,z;}tmp;
struct ljb{
	int head,h[10039];
	yyy f[200039];
	inline void add(int x,int y,int z,int g){
		f[head]=(yyy){y,z,g,h[x]};
		h[x]=head++;
	}
}s;
queue<int> q;
inline int bfs(){
	q.push(st);
	memset(d,-0x3f,sizeof(d));
	memset(flag,0,sizeof(flag));
	memset(g,0x3f,sizeof(g));
	d[st]=0;yyy tmp;
	while(!q.empty()){
		now=q.front();q.pop();
		for(beg(now);end;go){
			tmp=s.f[cur];
			if(tmp.g&&d[tmp.to]<d[now]+tmp.w){
				d[tmp.to]=d[now]+tmp.w;
				g[tmp.to]=min(g[now],tmp.g);
				flag[tmp.to]=1;
				q.push(tmp.to);
				pre[tmp.to]=cur;
			}
		}
	}
	return flag[t];
}
inline void get(int x,int y,int z,int g){s.add(x,y,z,g);s.add(y,x,-z,0);}
int main(){
	memset(s.h,-1,sizeof(s.h));
	register int i;
	scanf("%d",&n);t=2*n+3;st=2*n+2;get(st,0,0,4);get(2*n+1,t,0,4);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) get(0,i,0,1e9),get(i+n,2*n+1,0,1e9),get(i,i+n,1,1),get(i,i+n,0,1e9);
	for(i=1;i<=n;i++){
		if(fz[a[i]%7])get(fz[a[i]%7]+n,i,0,1e9);
		if(last[a[i]-1]) get(last[a[i]-1]+n,i,0,1e9);
		if(last[a[i]+1]) get(last[a[i]+1]+n,i,0,1e9);
		fz[a[i]%7]=last[a[i]]=i;
	}
	while(bfs()){
		ans+=g[t]*d[t];now=t;
		while(now!=st){
			s.f[pre[now]].g-=g[t];s.f[pre[now]^1].g+=g[t];
			now=s.f[pre[now]^1].to;
		}
	}
	printf("%d\n",ans);
}