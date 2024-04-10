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
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(!(n&1)){printf("%d %d\n",n>>1,n>>1);continue;}
		it flag=0,d;
		for(d=2;d*d<=n;++d) if(!(n%d)){flag=1;break;}
		if(!flag){printf("%d %d\n",1,n-1);continue;}
		printf("%d %d\n",n/d,n-n/d);
	}
	return 0;
}