#include<cstdio>
#include<cstring>
#include<queue>
#define beg(x) int cur=nows[x]
#define end ~cur
#define go cur=tmp.z
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;
int n,m,k,x,y,z,d[20039],nows[20039],now,st,t=20001,ans,a[20039],cnt,ts;
queue<int> q;
struct yyy{int to,w,z;}tmp;
struct ljb{
	int head,h[20039];
	yyy f[500039];
	inline void add(int x,int y,int z){
		f[head]=(yyy){y,z,h[x]};
		h[x]=head++;
	}
}s;
inline void get(int x,int y,int z){s.add(x,y,z);s.add(y,x,0);}
inline int bfs(){
	while(!q.empty()) q.pop();
	memset(d,0x3f,sizeof(d));memset(nows,0,sizeof(nows));
	q.push(st);d[st]=0;nows[st]=s.h[st];
	while(!q.empty()){
		now=q.front();q.pop();
		for(beg(now);end;go){
			tmp=s.f[cur];
			if(tmp.w&&d[tmp.to]>=1e9){
				d[tmp.to]=d[now]+1;q.push(tmp.to);nows[tmp.to]=s.h[tmp.to];
				if(tmp.to==t) return 1;
			}
		}
	}
	return 0;
}
inline int dfs(int x,int sum){
	if(x==t) return sum;
	yyy tmp;int pus=0,k;
	for(beg(x);end;go){
		tmp=s.f[cur];
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
	//freopen("1.in","r",stdin);
	register int i;memset(s.h,-1,sizeof(s.h));
	scanf("%d%d%d",&n,&m,&k);cnt=n;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(a[i])get(i,t,x);
		else get(st,i,x);
	}
	while(m--){
		scanf("%d%d%d",&x,&y,&ts);ans+=y;cnt++;
		while(ts--){
			scanf("%d",&z);
			if(x)get(z,cnt,1e9);
			else get(cnt,z,1e9);
		} 
		scanf("%d",&z);
		if(z)y+=k;
		if(x) get(cnt,t,y);
		else get(st,cnt,y);
	}
	while(bfs()) ans-=dfs(st,1e9);
	printf("%d\n",ans);
}