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
}
using io :: fr;
const int N=1000005;
set<int> A,B,S;
int n;
il int Min(ct p,ct q){return p<q?p:q;}
int main(){
	scanf("%d",&n);it i,num=0,tp,d;rll ans=0;
	for(i=1;i<=n;++i){
		scanf("%d%d",&tp,&d),ans+=d;
		if(d>0) tp?++num:(S.insert(d),0),A.size()&&d<=*A.rbegin()?A.insert(d):(ans+=d,B.insert(d));
		if(d<=0) d=-d,tp?--num:(S.erase(d),0),A.size()&&d<=*A.rbegin()?A.erase(d):(ans-=d,B.erase(d));
		while(B.size()<num) ans+=*A.rbegin(),B.insert(*A.rbegin()),A.erase(*A.rbegin());
		while(B.size()>num) ans-=*B.begin(),A.insert(*B.begin()),B.erase(*B.begin());
		printf("%lld\n",ans+Min(B.size()?(S.size()?*S.rbegin():0)-*B.begin():0,0));
	}
	return 0;
}