#include<cstdio>
using namespace std;
int n,m,k,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) printf("%d ",(i-1)/2*2+1);
		printf("\n");
	}
}