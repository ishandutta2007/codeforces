#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	scanf("%I64d",&n);
	for(long long i=1;i<=n;i++){
		if(i==1) puts("2");
		else printf("%I64d\n",i*i*i+2*i*i+1);
	}
	return 0;
}