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
const int N=1000005;
int T,n,hit[N][2],c[N],da[N],pre[N],suf[N],rd[N],cd[N],num,fa[N];
char s[N];
bool vs[N];
long long ans;
il void dfs(ct x){
	vs[x]=1,++num;
	if(cd[cd[x]]==x) return;
	if(!vs[cd[x]]) dfs(cd[x]);
}
int main(){ 
	scanf("%d",&T);it i,x;
	while(T--){
		scanf("%d%s",&n,s+1),ans=0;
		for(i=1;i<=n;++i) pre[i]=i-1,suf[i]=i+1,vs[i]=c[i]=hit[i][0]=hit[i][1]=rd[i]=cd[i]=0;pre[1]=n,suf[n]=1;
		for(i=1;i<=n;++i){
			if(s[i]=='L') ++rd[pre[i]],cd[i]=pre[i],fa[pre[i]]=i;
			if(s[i]=='R') ++rd[suf[i]],cd[i]=suf[i],fa[suf[i]]=i;
		}
		for(i=1;i<=n;++i) if(!rd[i]&&!vs[i]) num=-1,dfs(i),ans+=(num<=1?0:(num-1)/3+(num%3!=1));
		for(i=1;i<=n;++i) if(!vs[i]&&rd[i]==1&&cd[cd[i]]!=i){ans=(n-1)/3+1;break;}
		printf("%lld\n",ans);
	}
	return 0;
}