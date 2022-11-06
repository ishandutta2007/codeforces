#include <cstdio>
#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> a;)
const int mx = 1e5+10,
	      inf = 2e9;
int main(){
	int n, h[mx], d[mx];
	fill(d,d+n,inf);
	scanf("%d",&n);
	rep(i,0,n)
		scanf("%d",h+i);
	d[0] = 1;
	rep(i,1,n){
		d[i] = min(h[i], 1 + d[i-1]);
	}
	d[n-1] = 1;
	rrep(i,0,n-1){
		d[i] = min(d[i], 1 + d[i+1]);
	}
	int ans = -1;
	rep(i,0,n)
		ans = max(ans, d[i]);
	printf("%d\n",ans);
}