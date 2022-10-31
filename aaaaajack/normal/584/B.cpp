#include<cstdio>
#define Q 1000000007
using namespace std;
int main(){
	int a=1,b=1;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		a=1LL*a*27%Q;
		b=1LL*b*7%Q;
	}
	printf("%d\n",(a+Q-b)%Q);
	return 0;
}