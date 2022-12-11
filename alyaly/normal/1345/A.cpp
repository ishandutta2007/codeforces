#include<bits/stdc++.h>
#pragma GCC optimize(2)
//#define int long long
//#define P 998244353
using namespace std;
int T,n,m;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		if(n==1||m==1||(n==2&&m==2)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/*

*/