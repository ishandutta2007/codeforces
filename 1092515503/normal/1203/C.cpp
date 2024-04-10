#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,GCD,t;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int divisor(int x){
	int s=0;
	for(int i=1;i*i<=x;i++){
		if(x%i)continue;
		if(i*i==x)s++;
		else s+=2;
	}
	return s;
}
signed main(){
	scanf("%I64d%I64d",&n,&GCD);
	for(int i=1;i<n;i++)scanf("%I64d",&t),GCD=gcd(GCD,t);
	printf("%I64d\n",divisor(GCD));
	return 0;
}