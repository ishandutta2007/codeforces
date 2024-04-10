#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int fib[100100],n,m;
int main(){
	fib[0]=fib[1]=1;
	for(int i=2;i<=100000;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
	scanf("%d%d",&n,&m);
	printf("%d\n",((((fib[n]+fib[m])%mod+mod-1)%mod)*2)%mod);
	return 0;
}