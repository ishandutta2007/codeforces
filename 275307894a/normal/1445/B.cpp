#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&x,&y,&n,&m);
		printf("%d\n",max(x+y,n+m));
	}
}