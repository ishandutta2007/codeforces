#include<cstdio>

int main(){
	register int T,n,p,q,f1,i;
	scanf("%d",&T);
	while(T--){
		f1=0;
		scanf("%d%d%d",&n,&p,&q);
		while(p--){
			scanf("%d",&i);
			if(i==n)f1=1;
		}
		while(q--){
			scanf("%d",&i);
		}
		puts(f1?"YES":"NO");
	}
	return 0;
}