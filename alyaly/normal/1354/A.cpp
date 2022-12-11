#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<queue>
//#define P 998244353
using namespace std;
int T,a,b,c,d;
signed main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d;
		if(b>=a){
			printf("%lld\n",b);
		}else{
			if(c<=d) printf("-1\n");
			else{
				printf("%lld\n",((a-b-1)/(c-d)+1)*c+b);
			}
		}
	}
	return 0;
}
/*

*/