#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
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
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
	template <class I> 
	il void sp(I&p,I&q){I x=p;p=q,q=x;}
	template <class I> 
	il void ckMax(I& p,I q){p=(p>q?p:q);}
	template <class I> 
	il void ckMin(I& p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin;
const int N=1000005,inf=1e9;
int n,m,h[N],nxt[N],adj[N],u,v,t,mn[N],mx[N],val[N],id[N],a[N],rd[N];
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u,++rd[u],++rd[v];}
il bool cmp(ct p,ct q){return val[p]<val[q];}
int main(){
	scanf("%d%d",&n,&m);it i;  
	while(m--) scanf("%d%d",&u,&v),add();
	for(i=1;i<=n;++i) scanf("%d",&val[i]),id[i]=i,mn[i]=1;
	std::sort(id+1,id+1+n,cmp);
	for(it j=1;j<=n;++j){
		i=id[j],a[i]=mn[i];
	//	printf("%d %d %d %d\n",i,a[i],mn[i],val[i]);
	 //   if((!rd[i])&&(val[i]!=1)) return puts("-1"),0;
		if(a[i]!=val[i]) return puts("-1"),0;
		for(it k=h[i];k;k=nxt[k])
			if(mn[adj[k]]>=a[i]) mn[adj[k]]=a[i]+1;
			//mn[adj[k]]=Min(mn[adj[k]],a[i]>1?a[i]-1:a[i]+1);
	}
	for(i=1;i<=n;++i) printf("%d ",id[i]);
	return 0;
}