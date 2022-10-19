#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		printf("%d\n",(x==y?x*2:min(x,y)*2+(y+x-min(x,y)*2)*2-1));
	}
}