#include<stdio.h>
#include<vector>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
cll inf=1e18;
int T,n,k;
ll ans;
il void ckMin(rll &p,cll q){p=(p<q?p:q);}
il ll F(rll x){it ans=0;while(x) ans+=x%10,x/=10;return ans;}
il void ck(cll x){
	if(x<0) return ;
	it s=0;
	for(rll i=x;i<=x+k;++i) s+=F(i);
	if(s==n) ckMin(ans,x);
}
int main(){
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d%d",&n,&k),ans=inf;
		for(i=0;i<=100;++i) ck(i);
		for(rll now=9;now<inf;now=now*10ll+9)
			for(i=0;i<9;++i) for(rll x=(now+1)*i+now,j=x-20;j<=x+20;++j) ck(j);
		ans==inf?puts("-1"):printf("%lld\n",ans);
	}
	return 0;
}