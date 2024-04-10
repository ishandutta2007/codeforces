#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;} 
	template <class I> 
	il void sp(I&p,I&q){I x=p;p=q,q=x;} 
const int N=100005;
int T,n,m,totx,toty,a,b;
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d",&n,&m,&totx,&toty,&a,&b);it ans=0;
		if(a>b) sp(a,b),sp(totx,toty);
		for(it x=0,y,k,t;x<=totx;++x){
			if((0ll+x)*a>n) break;
			y=Min((n-x*a)/b,toty);
			k=Min(m/a,totx-x);
			t=Min((m-k*a)/b,toty-y);
			ans=Max(ans,x+y+k+t);
		}
		printf("%d\n",ans);
	}
	return 0;
}