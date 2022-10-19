#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1){printf("1\n");continue;}
		if(n==2){printf("2\n1 2\n");continue;}
		printf("2\n");
		printf("%d %d\n",n,n-2);
		printf("%d %d\n",n-1,n-1);
		for(int i=n-3;i;i--) printf("%d %d\n",i,i+2);
	}
}