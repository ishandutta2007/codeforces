#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<queue>
//#define P 998244353
using namespace std;
int n,s;
signed main(){
//	srand(time(0));
	cin>>n>>s;
	if(s>=2*n){
		printf("YES\n");
		for(int i=1;i<n;i++){
			printf("%lld ",2ll);
		}
		printf("%lld\n1\n",s-2*(n-1));
	}else{
		printf("NO\n");
	}
	return 0;
}
/*

*/