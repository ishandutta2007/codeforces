#include<cstdio>
using namespace std;
int main(){
	int a,r=0,b,count=0;
	scanf("%d%d",&a,&b);
	while(a>0){
		count+=a;
		r+=a;
		a=0;
		a+=r/b;
		r%=b;
	}
	printf("%d\n",count);
	return 0;
}