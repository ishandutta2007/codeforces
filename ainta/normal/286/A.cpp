#include<stdio.h>
int n,w[100001],i,p,q,c;
int main()
{
	scanf("%d",&n);
	if(n%4==2 || n%4==3){
		printf("-1\n");
		return 0;
	}
	p=2,q=n;
	for(i=1;i<=n/4;i++){
		w[++c]=p,w[++c]=q;
		p+=2,q-=2;
	}
	for(i=n;i>(n+1)/2;i--){
		w[i]=n+1-w[n+1-i];
	}
	if(n%4==1){
		w[n/2+1]=n/2+1;
	}
	for(i=1;i<=n;i++)printf("%d ",w[i]);
	return 0;
}