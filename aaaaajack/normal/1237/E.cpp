#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define Q 998244353
#define N 1001000
using namespace std;
int dp[22][N];
int main(){
	int n;
	scanf("%d",&n);
	int h=__lg(n+1),c=n+1-(1<<h);
	int c0=0,c1=1;
	for(int i=0;i<h-1;i++){
		int d0=c1*2,d1=c0+c1;
		c0=d0,c1=d1;
	}
	if(c==c0||c==c1) puts("1");
	else puts("0");
	return 0;
}