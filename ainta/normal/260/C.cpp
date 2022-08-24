#include<stdio.h>
__int64 n,x,w[100001],i,M=1999999999,P,y,a,b;
int main(){
	scanf("%I64d%I64d",&n,&x);
	x--;
	for(i=0;i<n;i++)scanf("%I64d",&w[i]);
	for(i=0;i<n;i++){
		if(M>w[i])M=w[i];
	}
	for(i=x+n;i>x;i--){
		if(w[i%n]==M)break;
	}
	y=i%n;
	a=(x+n-y)%n;
	b=n*w[y]+a;
	for(i=y+1;i<n+y;i++){
		w[i%n]-=w[y];
		if(a)a--,w[i%n]--;
	}
	w[y]=b;
	for(i=0;i<n;i++)printf("%I64d ",w[i]);
}