#include<stdio.h>
#include<string.h>
int D[5001][5001],n,i,j,Q,s,e;
char p[6000];
int main()
{
	scanf("%s",p);n=strlen(p);
	scanf("%d",&Q);
	for(i=0;i<n;i++){
		D[i][i]=1;
		s=i-1,e=i+1;
		while(s>=0&&e<n){
			if(p[s]!=p[e])break;
			D[s][e]=1;
			s--,e++;
		}
		s=i,e=i+1;
		while(s>=0&&e<n){
			if(p[s]!=p[e])break;
			D[s][e]=1;
			s--,e++;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			D[j][j+i]+=D[j+1][j+i]+D[j][j+i-1]-D[j+1][j+i-1];
		}
	}
	for(i=0;i<Q;i++){
		scanf("%d%d",&s,&e);
		printf("%d\n",D[s-1][e-1]);
	}
	return 0;
}