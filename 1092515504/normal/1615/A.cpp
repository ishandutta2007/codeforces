#include<bits/stdc++.h>
using namespace std;
int T,n,sum;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),sum=0;
		for(int i=1,x;i<=n;i++)scanf("%d",&x),sum+=x;
		printf("%d\n",!!(sum%n));
	}
	return 0;
}