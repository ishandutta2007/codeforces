#include<cstdio>
using namespace std;
int n,m,k,x,y,z,f[200039],t;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=1;i<2*k-n;i++) f[i]=i;f[2*k-n]=k;
		for(i=2*k-n+1;i<=k;i++)f[i]=f[i-1]-1;
		for(i=1;i<=k;i++) printf("%d ",f[i]);printf("\n"); 
	}
}