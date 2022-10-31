#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	long long x,y;
	scanf("%d",&T);
	while(T--){
		int n,z;
		scanf("%d",&n);
		x=y=0;
		while(n--){
			scanf("%d",&z);
			x+=z;
			y^=z;
		}
		printf("%d\n",2);
		printf("%lld %lld\n",y,x+y);
	}
	return 0;
}