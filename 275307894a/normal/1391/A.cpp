#include<cstdio>
using namespace std;
int t,n;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) printf("%d ",i);
		printf("\n");
	}
}