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
int T,n,a[N],ans[N];
char s[N];
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);it len=0;ans[0]=0;
		for(i=1;i<=n;++i){
			if(s[i]=='0') if(len) ans[++*ans]=len,len=0;
			len+=(s[i]=='1');
		}
		if(len) ans[++*ans]=len;
		std::sort(ans+1,ans+1+ans[0]);rll o=0;
		for(i=ans[0];i>=1;i-=2) o+=ans[i];
		printf("%lld\n",o);
	}
	return 0;
}