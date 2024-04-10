#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==0){
		printf("0 1\n0 %d\n0 0\n0 %d\n",m,m-1);
	}
	else if(m==0){
		printf("1 0\n%d 0\n0 0\n%d 0\n",n,n-1);
	}
	else if(m>=n){
		if(2*sqrt(m*m+n*n)+m<sqrt(m*m+n*n)+2*sqrt(m*m+(n-1)*(n-1))) printf("1 0\n%d %d\n0 0\n%d %d\n",n,m,n-1,m);
		else printf("0 0\n%d %d\n%d 0\n0 %d\n",n,m,n,m);
	}
	else{
		if(2*sqrt(m*m+n*n)+n<sqrt(m*m+n*n)+2*sqrt((m-1)*(m-1)+n*n)) printf("0 1\n%d %d\n0 0\n%d %d\n",n,m,n,m-1);
		else printf("0 0\n%d %d\n0 %d\n%d 0\n",n,m,m,n);
	}
	return 0;
}