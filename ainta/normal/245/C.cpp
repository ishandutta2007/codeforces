#include<stdio.h>
int n,w[101],i,C;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	if(n%2==0 || n==1){
		printf("-1\n");
		return 0;
	}
	for(i=n;i>=1;i--){
		while(w[i]){
			C++;
			w[i]--;
			if(i==1)continue;
			if(i%2==1){
				if(w[i-1])w[i-1]--;
			}
			else{
				if(w[i+1])w[i+1]--;
			}
			if(w[i/2])w[i/2]--;
		}
	}
	printf("%d\n",C);
}