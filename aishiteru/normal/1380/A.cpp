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
int T,n,a[N];
int main(){  
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);it ans1=-1,ans2=-1,i,j;
		for(i=1;i<=n;++i) scanf("%d",&a[i]);
		for(i=1;i<=n;++i){
			it pos1=0,pos2=0;
			for(j=1;j<i;++j)
				if(a[j]<a[i]){pos1=j;break;}
			if(!pos1) continue;
			for(j=i+1;j<=n;++j)
				if(a[i]>a[j]){pos2=j;break;}
			if(pos2){ans1=pos1,ans2=pos2;break;}
		}
		ans1==-1?puts("NO"):printf("YES\n%d %d %d\n",ans1,i,ans2);
	}
	return 0;
}