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
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
const int N=1000005;
int n,m,k,a[N],cn;
ll s[N],ans;
il bool cmp(ct p,ct q){return p>q;}
int main(){ 
	fr(n),fr(m),fr(k);it i,j;
	for(i=1;i<=n;++i) fr(a[i]),cn+=(a[i]>k);
	std::sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	//for(i=1;i<=n;++i) printf("%d ",a[i]);puts("");
	/*i=1,j=n;
	while(1){
		if(a[j]>k&&cn>1&&s[i+m-1]-s[i-1]<=a[j]&&i+m-1<j)
			ans+=a[j],i+=m,--j,--cn;
		else{
			while(i<=n&&i<j&&a[i]<=k) ans+=a[i],++i;
			ans+=a[j];
			break;
		}
	}
	hack:
	6 2 11
	8 10 12 15 23 5 
	56 (23 5 12 8 10 15)
	*/
	if(!cn) return printf("%lld",s[n]),0;
	for(i=1;i<=cn;++i){
		cll pos=n-i-(i-1ll)*m;
		if(pos<0) continue;
		ans=Max(ans,s[i]+(pos+cn>n?s[n]-s[cn]:s[cn+pos]-s[cn]));
	}
	printf("%lld",ans);
	return 0;
}