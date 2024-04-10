#include<stdio.h>
int D[1000001];
int main()
{
	int i,t,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		D[i]=999999999;
		t=i;
		while(t){
			if(D[i]>D[i-t%10]+1)D[i]=D[i-t%10]+1;
			t/=10;
		}
	}
	printf("%d\n",D[n]);
}