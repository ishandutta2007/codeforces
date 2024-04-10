#include<stdio.h>
int n,w[2001],C,M;
int inv(int a){
	int i,c=0;
	for(i=0;i<a;i++)if(w[i]>w[a])c++;
	for(i=a+1;i<n;i++)if(w[i]<w[a])c++;
	return c;
}
int main()
{
	int i,j,t;
	scanf("%d",&n);
	M=n*n;
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		if(w[i]<0)w[i]=-w[i];
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(w[i]>w[j])C++;
	if(M>C)M=C;
	for(i=0;i<n;i++){
		t=-inv(i);
		w[i]=-w[i];
		t+=inv(i);
		if(t>0)w[i]=-w[i];
		else C+=t;
	}
	printf("%d\n",C);
}