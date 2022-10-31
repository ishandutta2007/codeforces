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
int a[N],n,T,b[100][100];
char s[N];
int main(){ 
	scanf("%d",&T);it i,j;
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		for(i=0;i<10;++i) 
			for(a[i]=j=0;j<10;++j)
				b[i][j]=0;
		for(i=1;i<=n;++i) s[i]-='0',++a[s[i]];
		for(i=1;i<n;++i) ++b[s[i]][s[i+1]];
		it ans=n-1;
		for(i=0;i<10;++i) ans=Min(ans,n-a[i]);
		for(i=0;i<10;++i)
			for(j=0;j<10;++j){
				it cna=0,cnb=0;
				for(it k=1,fl=0;k<=n;++k)
					if(!fl&&s[k]==i) ++cna,fl=1;
					else if(fl&&s[k]==j) ++cnb,fl=0;
				ans=Min(ans,n-Min(cna,cnb)*2);
			}
		printf("%d\n",ans);
	}
	return 0;
}