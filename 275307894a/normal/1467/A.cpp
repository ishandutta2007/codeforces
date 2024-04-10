#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t,ans,a[200039];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1){printf("9\n");continue;}
		if(n==2){printf("98\n");continue;}
		a[1]=9;a[2]=8;
		for(int i=3;i<=n;i++)a[i]=(a[i-1]+1)%10;
		for(int i=1;i<=n;i++) printf("%d",a[i]);
		printf("\n");
	}
}