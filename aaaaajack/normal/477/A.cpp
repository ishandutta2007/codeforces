#include<cstdio>
#define Q 1000000007
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",(1LL*b*(b-1)/2%Q)*(1LL*a*(a+1)/2%Q*b%Q+a)%Q);
	return 0;
}