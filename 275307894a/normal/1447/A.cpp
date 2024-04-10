#include<cstdio>
using namespace std;
int n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);printf("%d\n",n);
		for(int i=1;i<=n;i++) printf("%d ",i);
		putchar('\n');
	}
}