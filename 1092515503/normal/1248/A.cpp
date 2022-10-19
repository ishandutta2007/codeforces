#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,t,n,m,c[2][2];
signed main(){
	scanf("%lld",&T);
	while(T--){
		memset(c,0,sizeof(c));
		scanf("%lld",&n);
		while(n--)scanf("%lld",&t),c[0][t&1]++;
		scanf("%lld",&m);
		while(m--)scanf("%lld",&t),c[1][t&1]++;
		printf("%lld\n",c[0][0]*c[1][0]+c[0][1]*c[1][1]);
	}
	return 0;
}