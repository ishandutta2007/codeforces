#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
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
};
using io :: fr;
const int N=1000005;
char s[N],t[N];
int n,T,ans[N];
int main(){ 
	scanf("%d",&T);it i,j,k,cn;
	while(T--){
		scanf("%d%s%s",&n,s+1,t+1);
		for(i=n,j=1,k=cn=0;n;++cn,ans[++k]=n--)
			cn&1?(s[i--]!=t[n]?ans[++k]=1:0):(s[j++]==t[n]?ans[++k]=1:0);
		printf("%d ",k);
		for(i=1;i<=k;++i) printf("%d ",ans[i]);puts("");
	}
	return 0;
}