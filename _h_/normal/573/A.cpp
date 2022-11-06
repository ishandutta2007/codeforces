#include <cstdio>
using namespace std;
int red(int a){
	while(a % 2 == 0)
		a /= 2;
	while(a % 3 == 0)
		a /= 3;
	return a;
}
int main(){
	int n, a, b;
	scanf("%d %d",&n,&a);
	a = red(a);
	for(int i = 1; i < n; ++i){
		scanf("%d",&b);
		if(red(b) != a){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}