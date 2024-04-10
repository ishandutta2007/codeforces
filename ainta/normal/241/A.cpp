#include<stdio.h>
int n,x,M,i,k,j,w[1001],s[1001],S,D,T;
int main(){
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)scanf("%d",&w[i]);
	for(i=0;i<n;i++)scanf("%d",&s[i]);
	S=s[0];M=s[0];
	for(i=0;i<n;i++){
		D=w[i];T+=w[i];
		if(D>S){
			T+=((D-S-1)/M+1)*k;
			S+=((D-S-1)/M+1)*M;}
		S-=D;
		if(i!=n-1){
			S+=s[i+1];
			if(M<s[i+1])M=s[i+1];}
	}
	printf("%d\n",T);
}