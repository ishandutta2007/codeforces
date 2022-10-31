#include<cstdio>
using namespace std;
int main(){
	int a,b,x;
	scanf("%d%d",&a,&b);
	if(a<b){
		puts("-1");
	}
	else{
		int k=(a+b)/(b+b);
		printf("%.10f\n",0.5*(a+b)/k);
	}
	return 0;
}