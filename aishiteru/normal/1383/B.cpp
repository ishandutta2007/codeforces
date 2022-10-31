#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005; 
int n,a[N],T;
int main(){ 
	scanf("%d",&T);it i,s,c0,c1,k;
	while(T--){
		scanf("%d",&n),s=c0=c1=k=0;
		for(i=1;i<=n;++i) scanf("%d",&a[i]),s^=a[i];
		if(!s){puts("DRAW");continue;}
		while((1<<k+1)<=s) ++k;
		for(i=1;i<=n;++i) c0+=!(a[i]>>k&1),c1+=(a[i]>>k&1);
		(((c1&3)==1)?1:(c0&1)) ? puts("WIN"):puts("LOSE");
	}
	return 0;
}