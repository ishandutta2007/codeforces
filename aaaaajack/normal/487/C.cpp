#include<cstdio>
using namespace std;
int inverse(int a,int p){
	int x=a,r=1,y=p-2;
	while(y){
		if(y&1) r=1LL*r*x%p;
		x=1LL*x*x%p;
		y>>=1;
	}
	return r;
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=2;i*i<=n;i++){
		if(n%i==0) break;
	}
	if(n==4){
		puts("YES");
		printf("1\n3\n2\n4\n");
	}
	else if(i*i<n) puts("NO");
	else{
		puts("YES");
		printf("1\n");
		for(i=1;i<n;i++){
			printf("%d\n",inverse(i,n)+1);
		}
	}
	return 0;
}