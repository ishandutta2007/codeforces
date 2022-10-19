#include<cstdio>
#include<queue>
#include<cstring>
#define beg(x) int cur=nows[x]
#define end ~cur
#define go cur=tmp.z
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
int n,m,k,x,y,z,d[4039],nows[4039],ans[139],a[3039],b[3039],now,tot,st,t,fs[3039];
struct yyy{int to,w,z;}tmp;
struct ljb{
	int head,h[4039];yyy f[100039];
	inline void add(int x,int y,int z){f[head]=(yyy){y,z,h[x]};h[x]=head++;}
}s;
inline void get(int x,int y,int z){s.add(x,y,z);s.add(y,x,0);}
queue<int> q;
inline int bfs(){
	while(!q.empty()) q.pop();
	memset(d,0x3f,sizeof(d));memset(nows,0,sizeof(nows));
	q.push(st);nows[st]=s.h[st];d[st]=0;
	while(!q.empty()){
		now=q.front();q.pop();
		for(beg(now);end;go){
			tmp=s.f[cur];
			if(tmp.w&&d[tmp.to]>=1e9){
				d[tmp.to]=d[now]+1;nows[tmp.to]=s.h[tmp.to];q.push(tmp.to);
				if(tmp.to==t) return 1;
			}
		}
	}
	return 0;
}
inline int dfs(int x,int sum){
	if(x==t) return sum;
	yyy tmp;int k,pus=0;
	for(beg(x);end;go){
		tmp=s.f[cur];nows[x]=cur;
		if(tmp.w&&d[tmp.to]==d[x]+1){
			k=dfs(tmp.to,min(tmp.w,sum));
			if(!k) d[tmp.to]=1e9;
			s.f[cur].w-=k;s.f[cur^1].w+=k;
			pus+=k;sum-=k;
		}
		if(!sum) break;
	}
	return pus;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;memset(s.h,-1,sizeof(s.h));
	scanf("%d",&n);st=0;t=n+1;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i]>0)get(st,i,b[i]),tot+=b[i];
		else get(i,t,-b[i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=a[i];j++)if(a[i]%j==0&&fs[j]) get(i,fs[j],1e9);
		fs[a[i]]=i;
	}
	while(bfs()) tot-=dfs(st,1e9);
	printf("%d\n",max(tot,0));
}