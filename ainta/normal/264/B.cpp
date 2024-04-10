#include<stdio.h>
int n,a,i,O[100010],j,o[1001],c,R,M;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a==1){
			if(!R)R=1;
		}
		c=0;
		for(j=2;j*j<=a;j++){
			if(a%j==0){
				o[++c]=j;
				while(a%j==0){
					a/=j;
				}
			}
		}
		if(a!=1)o[++c]=a;
		M=0;
		for(j=1;j<=c;j++)if(O[o[j]]>M)M=O[o[j]];
		M++;
		if(R<M)R=M;
		for(j=1;j<=c;j++)if(O[o[j]]<M)O[o[j]]=M;
	}
	printf("%d\n",R);
}