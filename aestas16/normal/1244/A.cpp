#include <cstdio>
 
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b,c,d,k,x,y;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		x=a/c,y=b/d;
		if(x*c!=a)x++;
		if(d*y!=b)y++;
		if(x+y<=k)printf("%d %d\n",x,y);
		else puts("-1");
	}
	return 0;
}