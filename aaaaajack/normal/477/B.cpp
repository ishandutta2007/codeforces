#include<cstdio>
using namespace std;
int main(){
	int i,n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",k*(6*n-1));
	for(i=0;i<n;i++){
		printf("%d %d %d %d\n",k*(6*i+1),k*(6*i+3),k*(6*i+4),k*(6*i+5));
	}
	return 0;
}