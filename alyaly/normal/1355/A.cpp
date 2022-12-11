#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<queue>
//#define P 998244353
using namespace std;
int T,n,K;
int calmi(int x){
	int nans=10;
	while(x){
		nans=min(nans,x%10);
		x/=10;
	}
	return nans;
}
int calmx(int x){
	int nans=0;
	while(x){
		nans=max(nans,x%10);
		x/=10;
	}
	return nans;
}
signed main(){
//	srand(time(0));
	cin>>T;
	while(T--){
		cin>>n>>K;
		if(K==1) printf("%lld\n",n);
		for(int i=1;i<K;i++){
			int nmi=calmi(n),nmx=calmx(n),ln=n;
			n+=nmi*nmx;
			if(n==ln||i==K-1){
				printf("%lld\n",n);
				break;
			}
		}
	}
	return 0;
}
/*

*/