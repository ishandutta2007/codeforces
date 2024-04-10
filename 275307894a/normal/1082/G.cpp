#include<cstdio>
#include<cstring>
#include<queue>
#define min(a,b) ((a)<(b)?(a):(b))
#define beg(x) int cur=nows[x]
#define end ~cur
#define go cur=tmp.z
using namespace std;
int n,m,k,x,y,z,nows[2039],d[2039],st,t,now;
long long ans;
struct yyy{int to,w,z;}tmp;
struct ljb{
	int head,h[2039];
	yyy f[200039];
	inline void add(int x,int y,int z){
		f[head]=(yyy){y,z,h[x]};
		h[x]=head++;
	}
}s;
queue<int> q;
inline void get(int x,int y,int z){s.add(x,y,z);s.add(y,x,0);}
inline int bfs(){
	while(!q.empty()) q.pop();
	memset(nows,0,sizeof(nows));memset(d,0x3f,sizeof(d));
	d[st]=0;q.push(st);nows[st]=s.h[st];
	while(!q.empty()){
		now=q.front();q.pop();
		for(beg(now);end;go){
			tmp=s.f[cur];
			if(tmp.w&&d[tmp.to]>=1e9){
				d[tmp.to]=d[now]+1;q.push(tmp.to);nows[tmp.to]=s.h[tmp.to];
				if(tmp.to==t)return 1;
			}
		}
	}
	return 0;
}
inline int dfs(int x,int sum){
	if(x==t) return sum;
	int pus=0,k;yyy tmp;
	for(beg(x);end;go){
		tmp=s.f[cur];nows[x]=cur;
		if(tmp.w&&d[tmp.to]==d[x]+1){
			k=dfs(tmp.to,min(tmp.w,sum));
			if(!k) d[tmp.to]=1e9;
			s.f[cur].w-=k;s.f[cur^1].w+=k;
			sum-=k;pus+=k;
		}
		if(!sum) break;
	}
	return pus;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;memset(s.h,-1,sizeof(s.h));
	scanf("%d%d",&n,&m);st=0;t=n+m+1;
	for(i=1;i<=n;i++)scanf("%d",&x),get(st,i,x);
	for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),get(x,n+i,2e9),get(y,n+i,2e9),get(n+i,t,z),ans+=z;
	while(bfs()) ans-=dfs(st,2e9);
	printf("%lld\n",ans>0?ans:0);
}