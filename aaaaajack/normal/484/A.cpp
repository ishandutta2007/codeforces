#include<cstdio>
using namespace std;
long long check(long long l,long long r){
	long long x=1;
	while((x<<1)<=r) x<<=1;
	if(r==(x<<1)-1) return r;
	if(l&x){
		return x|check(l^x,r^x);
	}
	else{
		return x-1;
	}
}
		
int main(){
	int n;
	long long l,r;
	scanf("%d",&n);
	while(n--){
		scanf("%I64d%I64d",&l,&r);	
		printf("%I64d\n",check(l,r));
	}
	return 0;
}