#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,K,p,fl[100001];
int qread(){
	int nans=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		nans*=10;
		nans+=c-'0';
		c=getchar();
	}
	return nans;
}
signed main(){
	T=qread();
	for(int i=1;i<=100000;i++) fl[i]=-1;
	while(T--){
		n=qread();
		int nfl=0;
		for(int i=1;i<=n;i++){
			K=qread();
			bool gfl=0;
			for(int j=1;j<=K;j++){
				p=qread();
				if(fl[p]!=T){
					if(!gfl) fl[p]=T;
					gfl=1;
				}
			}
			if(!gfl) nfl=i;
		}
		if(nfl){
			for(int i=1;i<=n;i++){
				if(fl[i]!=T){
					printf("IMPROVE\n");
					printf("%lld %lld\n",nfl,i);
					break;
				}
			}
		}else{
			printf("OPTIMAL\n");
		}
	}
	return 0;
}