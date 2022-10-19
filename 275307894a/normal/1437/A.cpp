#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(n*2>m) printf("Yes\n");
		else printf("No\n");
	}
}