#include<cstdio>
using namespace std;
long long gcd(long long x,long long y){
	while(y){
		x%=y;
		x^=y,y^=x,x^=y;
	}
	return x;
}
int main(){
	long long x,y;
	scanf("%I64d%I64d",&x,&y);
	if(gcd(x,y)>1) puts("Impossible");
	else{
		while(x&&y){
			if(x>y){
				printf("%I64dA",x/y-(y==1));
				x%=y;
			}
			else{
				printf("%I64dB",y/x-(x==1));
				y%=x;
			}
		}
	}
	return 0;
}