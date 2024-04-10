#include<cstdio>
using namespace std;
int t,x,y;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		printf("%d\n",x^y);
	}
}