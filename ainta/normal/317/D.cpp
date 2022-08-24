#include<stdio.h>
int n,i,j,w[30]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12},P=1,L,c;
bool v[100001];
int main()
{
	scanf("%d",&n);
	L=n-1;
	for(i=2;i*i<=n;i++){
		if(v[i])continue;
		j=i;
		c=0;
		while(1){
			L--,c++;
			if(j<=n/j)v[j]=true;
			if(j>n/i)break;
			j*=i;
		}
		P^=w[c];
	}
	P^=(L&1);
	printf(P?"Vasya":"Petya");
}