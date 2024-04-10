#include <cstdio>
using namespace std;
int f(int x){
	if (!x) return 0;
	return x%10+f(x/10);
}
int main(){
	int k,i=10;
	scanf("%d",&k);
	for (;k;i+=9)if (f(i)==10)k--;
	printf("%d\n", i-9);
	return 0;
}