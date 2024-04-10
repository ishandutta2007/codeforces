#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
#define P 998244353
typedef long long ll;
#define rll register ll
#define cll const ll
int o,neg,a,b;
il void que(ct p,ct q){printf("? %d %d\n",p,q),fflush(stdout),scanf("%d",&o);}
int main(){
	que(0,0),neg=o;it i;
	for(i=29;~i;--i){
		que((1<<i)|a,(1<<i)|b);
		if(o==neg) que((1<<i)|a,b),o==-1?a|=(1<<i),b|=(1<<i):0;
		else neg==1?a|=(1<<i):b|=(1<<i),que(a,b),neg=o;
	}
	printf("! %d %d\n",a,b),fflush(stdout);
	return 0;
}