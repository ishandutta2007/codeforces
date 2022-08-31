#include<stdio.h>
int n,D[100],chk[100],s[100],k,z;
int p(int a){
	for(k=0;k<a;k++) z*=10;
	return z;
}
int main(){
	int i,j;
	scanf("%d",&n);
	chk[4]=chk[7]=1;
	for(i=8;i<=25;i++)if(chk[i-4]==1||chk[i-7]==1)chk[i]=1;
	D[4]=4,D[7]=7,s[4]=1,s[7]=1;
	for(i=8;i<=25;i++){
		if(chk[i]==0)continue;
		if(chk[i-4]==1&&chk[i-7]==1){
			z=1;
			if(D[i-4]+p(s[i-4])*4<D[i-7]*10+7){
				z=1;
				D[i]=D[i-4]+p(s[i-4])*4,s[i]=s[i-4]+1;}
			else D[i]=D[i-7]*10+7,s[i]=s[i-7]+1;
		}
		else if(chk[i-4]){
			z=1;
			D[i]=D[i-4]+p(s[i-4])*4,s[i]=s[i-4]+1;
		}
		else if(chk[i-7]){
			D[i]=D[i-7]*10+7,s[i]=s[i-7]+1;
		}
	}
	if(n<=17){if(chk[n]==0){printf("-1\n");return 0;}}
	for(i=n;;i-=7)if(i<=25)break;
	printf("%d",D[i]);
	if(i>=8)for(j=0;j<(n-i)/7;j++)printf("7");
}