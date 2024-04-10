#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n&1){
		printf("black\n");
	}
	else{
		printf("white\n");
		printf("1 2\n");
	}
	return 0;
}