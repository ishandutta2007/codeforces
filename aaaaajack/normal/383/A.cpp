#include<cstdio>
using namespace std;
int main(){
	int n,x,sum=0;
	long long count=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(x) sum++;
		else count+=sum;
	}
	printf("%I64d\n",count);
	return 0;
}