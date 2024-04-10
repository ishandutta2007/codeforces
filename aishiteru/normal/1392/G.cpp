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
const int N=1050005;
int l[N],r[N],n,m,k,ansl,ansr,ans,p[N];
char s[N],t[N];
int main(){ 
	scanf("%d%d%d",&n,&m,&k);it i,j,cns=0,cnt=0;
	scanf("%s%s",s+1,t+1);ct lim=1<<k;
	for(i=1;i<=k;++i) s[i]-='0',t[i]-='0',p[i]=i,cns+=s[i],cnt+=t[i];
	for(i=0;i<lim;++i) l[i]=1e9,r[i]=-l[i];
	for(it i=1,j,x,y,sta;i<=n;++i){
		scanf("%d%d",&x,&y);
		for(sta=0,j=1;j<=k;++j) sta|=s[j]<<p[j]-1;
		l[sta]=Min(l[sta],i),sp(p[x],p[y]);
		for(sta=0,j=1;j<=k;++j) sta|=t[j]<<p[j]-1;
		r[sta]=Max(r[sta],i);
	}
	for(it d=1,p;d<lim;d<<=1)
		for(i=0,p=d<<1;i<lim;i+=p)
			for(j=0;j<d;++j)
				ckMin(l[i+j],l[i+j+d]),ckMax(r[i+j],r[i+j+d]);
	ans=-1,ansl=ansr=0;
	for(i=0;i<lim;++i)
		if(r[i]-l[i]+1>=m)
			if(__builtin_popcount(i)>ans) ans=__builtin_popcount(i),ansl=l[i],ansr=r[i];
	printf("%d\n%d %d\n",k+(ans<<1)-cns-cnt,ansl,ansr);
	return 0;
}