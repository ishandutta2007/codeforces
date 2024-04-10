#include<cstdio>
using namespace std;
int n,t,m,k;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1) printf("0\n");
		else if(n==2) printf("1\n");
		else if(n==3) printf("2\n");
		else {
			printf("%d\n",2+(n%2==0?0:1));
		}
	}
}