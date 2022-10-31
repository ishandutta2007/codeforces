#include<cstdio>
using namespace std;
int x[100100];
int main(){
	int n,k,i,j,y;
	scanf("%d%d",&n,&k);
	if((n==1&&k>0)||(n/2)>k) printf("-1\n");
	else if(n==1) printf("1\n");
	else{
		y=k-n/2+1,j;
		j=(n+10000)/y+1;
		for(i=0;i<2*(n/2-1);i++) x[i]=i+2;
		x[2*(n/2)-2]=y*j;
		x[2*(n/2)-1]=y*(j+1);
		if(n%2) x[n-1]=1;
		for(i=0;i<n-1;i++) printf("%d ",x[i]);
		printf("%d\n",x[n-1]);
	}
	return 0;
}