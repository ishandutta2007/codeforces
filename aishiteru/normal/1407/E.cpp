
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
typedef long double ldb;
typedef unsigned long long ull;
#define pb push_back
#define mkp make_pair
#define pl pair<ll,int> 
#define pi pair<int,int>
#define fir first
#define sec second
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
	il void ckMax(I&p,I q){p=(p>q?p:q);}
	template <class I>
	il void ckMin(I&p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin; 
const int N=1000005;
int h[N],nxt[N],adj[N],n,t,u,v,x,col[N],d[N],q[N],top1,top2,w[N],top,m;
il void add(){nxt[++t]=h[v],h[v]=t,adj[t]=u,w[t]=x;}
int main(){
	scanf("%d%d",&n,&m);it i;
	for(i=1;i<=m;++i) scanf("%d%d%d",&u,&v,&x),add();
	for(i=1;i<=n;++i) d[i]=col[i]=-1;
	d[n]=0,q[++top2]=n;
	while(top1<top2){
		top=q[++top1];
		for(i=h[top];i;i=nxt[i])
			if(!(~col[adj[i]])) col[adj[i]]=w[i]^1;
			else if(col[adj[i]]==w[i]&&(!(~d[adj[i]]))) d[adj[i]]=d[top]+1,q[++top2]=adj[i];
	}
	printf("%d\n",d[1]);
	for(i=1;i<=n;++i) printf("%d",~col[i]?col[i]:0);
	return 0;
}