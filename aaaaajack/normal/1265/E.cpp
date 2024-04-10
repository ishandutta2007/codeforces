#include<bits/stdc++.h>
#define N 200100
#define Q 998244353
using namespace std;
int d[N],s[N];
inline int inv(int x){
	int y=Q-2;
	int r=1;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
int main(){
	int n,pre=0,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		long long nw=(100LL*inv(x)+(100LL-x)*inv(x)%Q*pre)%Q;
		pre=(pre+nw)%Q;
	}
	printf("%d\n",pre);
	return 0;
}