#include<cstdio>
#include<queue>
#include<cstring>
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
using namespace std;
int n,m,k,x,y,z,st,tot[300039],now,w[300039];
long long d[300039],ans;
struct yyy{int to,w,z,id;}tmp;
struct ljb{
	int head,h[300039];
	yyy f[600039];
	inline void add(int x,int y,int z,int id){
		f[++head]=(yyy){y,z,h[x],id};
		h[x]=head;
	}
}s;
queue<int> q;
int main(){
	//freopen("1.in","r",stdin);
	memset(d,0x3f,sizeof(d));
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&w[i]),s.add(x,y,w[i],i),s.add(y,x,w[i],i);
	scanf("%d",&st);
	q.push(st);d[st]=0;
	while(!q.empty()){
		now=q.front();
		q.pop();
		for(beg(now);end;go){
			tmp=s.f[cur];
			if(d[tmp.to]>d[now]+tmp.w) tot[tmp.to]=tmp.id,d[tmp.to]=d[now]+tmp.w,q.push(tmp.to);
			else if(d[tmp.to]==d[now]+tmp.w) tot[tmp.to]=w[tot[tmp.to]]>tmp.w?tmp.id:tot[tmp.to];
		}
	}
	for(i=1;i<=n;i++) if(tot[i]) ans+=w[tot[i]];
	printf("%lld\n",ans);
	for(i=1;i<=n;i++) if(tot[i]) printf("%d ",tot[i]);
}