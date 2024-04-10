#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	int n, ans = 0, a, p, mi = 1e9;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d%d",&a,&p);
		mi = min(mi, p);
		ans += mi * a;
	}
	printf("%d\n",ans);
}