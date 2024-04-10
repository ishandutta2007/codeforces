#include<cstdio>
using namespace std;
int n,m,k,x,y,z;
int main(){
	register int i;
	scanf("%d",&n);
	if(n<=3) printf("NO\n");
	else{
		printf("YES\n");
		if(n&1){
			printf("4 + 5 = 9\n");
			printf("3 * 9 = 27\n");
			printf("27 - 2 = 25\n");
			printf("25 - 1 = 24\n");
			for(i=1;i<=n-5;i+=2) printf("%d - %d = 1\n24 * 1 = 24\n",i+6,i+5);
		}
		else{
			printf("1 * 2 = 2\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");
			for(i=1;i<=n-4;i+=2) printf("%d - %d = 1\n24 * 1 = 24\n",i+5,i+4);
		}
	}
}//////