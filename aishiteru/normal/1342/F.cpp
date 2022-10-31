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
const int N=1<<15,inf=2139062143;
int T,f[16][16][N],a[N],pw[N],sum[N],n,lim;
pi pre[16][16][N];
il void del(it x){while(x<n) --a[x],++x;}
il void puo(ct i,ct j,ct s){
	if(!s) return;
	ct ss=s^pre[i][j][s].fir;
	for(it x=0;x<n;++x) if(x!=j-1&&(ss&pw[x])) printf("%d %d\n",a[x],a[j-1]),del(x);
	puo(i-1,pre[i][j][s].sec,pre[i][j][s].fir);
}
int main(){ 
	scanf("%d",&T);it i,j,s,ss,tj,k,fl;
	for(i=pw[0]=1;i<=30;++i) pw[i]=pw[i-1]<<1;
	while(T--){
		scanf("%d",&n),lim=1<<n;
		for(i=0;i<=n;++i) for(j=0;j<=n;++j) memset(f[i][j],127,lim<<2);
		for(i=0;i<lim;++i) sum[i]=0;
		for(i=0;i<n;++i) scanf("%d",&j),sum[pw[i]]=j,a[i]=i+1;
		for(i=0;i<lim;++i) sum[i]=sum[i&(i-1)]+sum[i&(-i)];
		for(i=f[0][0][0]=0,--lim;i<n;++i)
			for(s=0;s<=lim;++s)
				for(j=0;j<n;++j)
					if(f[i][j][s]<inf)
						for(ss=lim^s,k=ss;k;k=(k-1)&ss)
							if(sum[k]>f[i][j][s]&&(k>>j))
								if(f[i+1][tj=j+__builtin_ctz(k>>j)+1][s|k]>sum[k])
									f[i+1][tj][s|k]=sum[k],pre[i+1][tj][s|k]=mkp(s,j);
		for(i=n,fl=1;fl&&i;--i) for(j=1;fl&&j<=n;++j) if(f[i][j][lim]!=inf) printf("%d\n",n-i),puo(i,j,lim),fl=0;
	}
	return 0;
}