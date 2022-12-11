#include<bits/stdc++.h>
#define int long long
#define P 998244353
using namespace std;
int T,n,na,d[101],pd;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		na=1;
		pd=0;
		for(int i=2;na+i<=n;i*=2){
			d[++pd]=i;
			na+=i;
		}
		if(na!=n){
			d[++pd]=n-na;
		}
		d[0]=1;
		for(int i=pd;i>=1;i--){
			if(d[i]<d[i-1]) swap(d[i],d[i-1]);
		}
		printf("%lld\n",pd);
		for(int i=1;i<=pd;i++){
			printf("%lld ",d[i]-d[i-1]);
		}
		printf("\n");
	}
	return 0;
}
/*

*/