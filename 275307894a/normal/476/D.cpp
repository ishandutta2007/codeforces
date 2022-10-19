#include<cstdio>
using namespace std;
int n,m,k,x,y,z;
int main(){
	register int i;
	scanf("%d%d",&n,&k);
	printf("%d\n",k*(6*n-1));
	for(i=1;i<=n;i++) printf("%d %d %d %d\n",(i*6-5)*k,(i*6-4)*k,(i*6-3)*k,(i*6-1)*k);
}