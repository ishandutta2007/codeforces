#include<cstdio>
using namespace std;
int n,t,m,k;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++){
			if(i%3==1) putchar('a');
			else if(i%3==2) putchar('b');
			else putchar('c');
		}
		putchar('\n');
	}
}