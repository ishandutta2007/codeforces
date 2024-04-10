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
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
const int N=1000005;
int T,n,a[N],b[N];
int main(){  
	scanf("%d",&T);it i,x,j;
	while(T--){
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;++i) scanf("%d",&a[i]);
		std::sort(a+1,a+1+n);
		for(i=1;i<=n;++i) b[i]=(x-1)/a[i]+1;
		it r=0,ans=0;
		for(i=n;i;--i){
			it num=0;
			for(j=i;j&&b[j]==b[i];--j) ++num;
			ans+=num/b[i],r+=num%b[i],ans+=r/b[i],r%=b[i],i=j+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}