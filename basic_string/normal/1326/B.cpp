#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n,i;
	long long j,k;
	scanf("%d",&n);
	scanf("%lld",&j);
	printf("%lld ",j),k=j;
	for(i=1;i<n;++i){
		scanf("%lld",&j);
		printf("%lld ",k+j),k=max(k,k+j);
	}
	return 0;
}//