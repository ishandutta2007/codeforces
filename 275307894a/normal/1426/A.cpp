#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(n<=2) printf("1\n");
		else if((n-2)%m==0)printf("%d\n",(n-2)/m+1);
		else printf("%d\n",(n-2)/m+2);
	}
}