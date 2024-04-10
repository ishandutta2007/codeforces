#include<cstdio>
using namespace std;
int n,m,k,x,y;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		if(x%y==0) printf("0\n");
		else printf("%d\n",y-x%y);
	}
}