#include<cstdio>
using namespace std;
int n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) printf("%d ",2*n+2*i);
		printf("\n");
	}
}