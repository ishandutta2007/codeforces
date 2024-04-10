#include<cstdio>
#include<algorithm>
#include<cmath>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long a,b,k,x,y,ans=1e18,pus=5e18,pos,now;
inline void push(long long s){
	now=(s-x%s)%s;
	if((x+now)*(y+now)/s<pus) pus=(x+now)*(y+now)/s,ans=now;
	else if((x+now)/s*(y+now)==pus&&ans>now) ans=now;
}
int main(){
	register int i;
	scanf("%lld%lld",&x,&y);
	if(x>y) x^=y,y^=x,x^=y;
	if(y%x==0){printf("0\n");return 0;}
	for(i=1;i*i<=y-x;i++){
		if((y-x)%i==0){
			push(i);
			push((y-x)/i);
		}
	}
	printf("%lld\n",ans);
}