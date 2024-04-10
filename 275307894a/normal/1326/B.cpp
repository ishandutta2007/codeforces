#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,a,b;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		printf("%d ",b+a);
		b=max(b+a,b);
	}
}