#include<cstdio>
using namespace std;
int n,m,k,x,y;
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(y-x>=2) k++;
	}
	printf("%d\n",k);
}