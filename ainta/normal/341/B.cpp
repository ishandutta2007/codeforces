#include<stdio.h>
int n,w[100001],i,a,B,E,M,SZ;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(!i){
			w[++SZ]=a;
			continue;
		}
		if(w[SZ]<a){
			w[++SZ]=a;
			continue;
		}
		B=1,E=SZ;
		while(B<=E){
			M=(B+E+1)>>1;
			if(w[M]>a && a>w[M-1]){
				break;
			}
			if(w[M]<a)B=M+1;
			else E=M-1;
		}
		w[M]=a;
	}
	printf("%d\n",SZ);
}