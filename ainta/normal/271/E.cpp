#include<stdio.h>
__int64 R;
int i,n,G,m,c;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void ins(int a){
	while(a<m){
		R+=m-a;
		a<<=1;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&c);
		c--;
		if(!i)G=c;
		else G=gcd(G,c);
	}
	while(!(G&1))G>>=1;
	c=0;
	for(i=1;i*i<=G;i++){
		if(G%i==0){
			ins(i);
			if(G!=i*i)ins(G/i);
		}
	}
	printf("%I64d\n",R);
}