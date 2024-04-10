#include<cstdio>
using namespace std;
int n,t;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n&1){
			putchar('7');
			for(i=1;i<=n/2-1;i++) putchar('1');
		}
		else for(i=1;i<=n/2;i++) putchar('1');
		putchar('\n');
	}
}