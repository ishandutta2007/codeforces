#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int t,x,y,z,ans,tot,s,ts;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&x,&y,&z);
		s=max(x,max(y,z));
		if(s>x+y+z-s) ans=x+y+z-s;
		else ans=(x+y+z)/2;
		printf("%d\n",ans);
	}
	return 0;
}