#include<cstdio>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1) printf("1\n");
	else if(m-1>=n-m){
		printf("%d\n",m-1);
	}
	else printf("%d\n",m+1);
	return 0;
}