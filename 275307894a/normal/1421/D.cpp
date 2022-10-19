#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long t,n,m,k,x,y,z,c1,c2,c3,c4,c5,c6;
long long ans;
int main(){
	register int i;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&x,&y);
		scanf("%lld%lld%lld%lld%lld%lld",&c1,&c2,&c3,&c4,&c5,&c6);
		for(i=1;i<=10;i++)c1=min(c1,c2+c6),c2=min(c2,c3+c1),c3=min(c3,c4+c2),c4=min(c4,c3+c5),c5=min(c5,c4+c6),c6=min(c6,c1+c5);
		if(x>=0&&y>=0){
			if(x>y) ans=c1*y+c6*(x-y);
			else ans=c1*x+c2*(y-x);
		}
		else if(x>=0&&y<=0){
			y*=-1;
			ans=x*c6+c5*y;
		}
		else if(x<=0&&y>=0){
			x*=-1;
			ans=x*c3+y*c2;
		}
		else {
			x*=-1;y*=-1;
			if(x>y) ans=c4*y+c3*(x-y);
			else ans=c4*x+c5*(y-x); 
		}
		printf("%lld\n",ans);
	}
}