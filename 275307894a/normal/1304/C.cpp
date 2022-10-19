#include<cstdio>
//#include<cmath>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
int n,m,k,t,l,r,ls,rs,x,y,z,ts,flag;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		l=r=m;
		flag=0;ts=0;
		for(i=1;i<=n;i++) {
			scanf("%d%d%d",&z,&x,&y);
			l-=abs(z-ts);
			r+=abs(z-ts);
			l=max(l,x);
			r=min(r,y);
			ts=z;
			//printf("%d %d\n",l,r);
			if(l>r) flag=1;
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
}