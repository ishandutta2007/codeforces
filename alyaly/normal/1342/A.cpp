#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,a,b;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>a>>b;
		if(2*a>=b) printf("%lld\n",b*min(n,m)+a*(max(n,m)-min(n,m)));
		else printf("%lld\n",2*a*min(n,m)+a*(max(n,m)-min(n,m)));
	}
	return 0;
}
/*

*/