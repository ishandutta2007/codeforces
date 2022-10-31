#include<cstdio>
using namespace std;
int main(){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	if(n*k>n*(n-1)/2) printf("-1\n");
	else{
		printf("%d\n",n*k);
		for(i=1;i<=n;i++){
			for(j=1;j<=k;j++){
				printf("%d %d\n",i,(i+j-1)%n+1);
			}
		}
	}
	return 0;
}