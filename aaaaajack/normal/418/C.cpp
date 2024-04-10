#include<cstdio>
using namespace std;
void fill(int *a,int n){
	if(n==1) a[0]=1;
	else if(n==2){
		a[0]=3,a[1]=4;
	}
	else if(n%2){
		for(int i=0;i<n-2;i++) a[i]=1;
		a[n-2]=2;
		a[n-1]=(n+1)/2;
	}
	else{
		for(int i=0;i<n-1;i++) a[i]=1;
		a[n-1]=(n-2)/2;
	}
}
int main(){
	int n,m,i,j;
	int a[200],b[200];
	scanf("%d%d",&n,&m);
	fill(a,n);
	fill(b,m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d",a[i]*b[j]);
			if(j==m-1) putchar('\n');
			else putchar(' ');
		}
	}
	return 0;
}