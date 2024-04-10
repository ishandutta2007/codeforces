#include<stdio.h>
#include<string.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
};
using io :: fr;
int h[N],nxt[N],adj[N],u,v,t,ans,n,k,top1,top2,d[N],T,rd[N];
bool inq[N];
struct ky{
	int u,d;
}q[N];
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;}
il void bfs(){
	top1=top2=0;register ky top;ans=0;
	for(it i=1;i<=n;++i) if(rd[i]==1) q[++top2]=(ky){i,1};
	while(top1<top2){
		top=q[++top1],inq[top.u]=1;
		for(it i=h[top.u],j;i;i=nxt[i])
			if(!inq[j=adj[i]]){
				++d[j];
				if(d[j]%k==0){
					++ans;
					if(d[j]==rd[j]-1) q[++top2]=(ky){j,top.d+1};
				}
			}
	}
}
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;++i) h[i]=d[i]=inq[i]=rd[i]=0;t=0;
		for(i=1;i<n;++i) scanf("%d%d",&u,&v),add(),++rd[u],++rd[v];
		bfs(),printf("%d\n",ans);
	}
	return 0;
}