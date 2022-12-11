#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
signed main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m;
		printf("%lld\n",((n-1)/m+1)*m-n);
	}
	return 0;
}