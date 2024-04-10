#include<stdio.h>
#define it register int
#define ct const int
#define il inline 
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
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
const int N=5005;
int n,m,a[N][N],f[N][N];
long long ans;
char s[N];
int main(){ 
	scanf("%d%d",&n,&m);it i,j;
	for(i=1;i<=n;++i){
		scanf("%s",s+1);
		for(j=1;j<=m;++j) a[i][j]=s[j]-'a'+1;
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			f[i][j]=(a[i][j]!=a[i-1][j]||a[i][j]!=a[i-1][j+1]||a[i][j]!=a[i-1][j-1]||a[i][j]!=a[i-2][j])?1:Min(Min(f[i-1][j-1],f[i-1][j+1]),f[i-2][j])+1,ans+=f[i][j];
	printf("%lld",ans);
	return 0;
}