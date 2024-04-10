#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int T,n;
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n<=30){puts("NO");continue;}
		if(n==36||n==40||n==44){
			if(n==36) puts("YES"),puts("5 6 10 15");
			if(n==40) puts("YES"),puts("6 10 15 9");
			if(n==44) puts("YES"),puts("6 7 10 21");
			continue;
		}
		printf("YES\n%d %d %d %d\n",6,10,14,n-30);
	}
	return 0;
}