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
int T,n,a[N],ans[N],b[N],sum[N];
char s[N];
map<int,int> mp;
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d%s",&n,s+1),b[0]=0,mp.clear();
		for(i=1;i<=n;++i) a[i]=s[i]-'0',sum[i]=sum[i-1]+a[i];
		for(i=0;i<=n;++i){
			sum[i]-=i;
			if(!mp.count(sum[i])) b[++*b]=sum[i];
			++mp[sum[i]];
		}
		//for(i=0;i<=n;++i) printf("%d ",sum[i]);puts("");
		rll ans=0;
		for(i=1;i<=b[0];++i) ans=ans+(0ll+mp[b[i]])*(mp[b[i]]-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}