#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		long long a,b,x,y;
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		printf("%lld\n",min(min(x,y)*b+abs(x-y)*a,(x+y)*a));
	}
}