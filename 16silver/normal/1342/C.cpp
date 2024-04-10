#include <bits/stdc++.h>
using namespace std;
int x[50000];
int a,b,q;
long long f(long long z){
	return z/(a*b)*x[a*b-1] + x[z%(a*b)];
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		scanf("%d%d%d",&a,&b,&q);
		for(int i=0;i<a*b;i++){
			if((i%a)%b != (i%b)%a) x[i]=1;
			else x[i]=0;
			if(i!=0) x[i]+=x[i-1];
		}
		for(int i=0;i<q;i++){
			long long c,d;
			scanf("%lld%lld",&c,&d);
			printf("%lld ",f(d)-f(c-1));
		}
		puts("");
	}
}