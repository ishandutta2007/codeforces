#include<cstdio>
using namespace std;
int n,m,k,x,y;
int main(){
	register int i;
	scanf("%d",&n);
	for(i=2;i*i<=n;i++) if(n%i==0){printf("%d%d",i,n/i);return 0;}
}