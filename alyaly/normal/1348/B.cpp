#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
int T,n,K,a[200003],an,hsh[203],ffl,ga[203];
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;
		ffl=0;
		memset(hsh,0,sizeof(hsh));
		memset(ga,0,sizeof(ga));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			hsh[a[i]]=1;
		}
		int na=0;
		for(int i=1;i<=n;i++){
			if(hsh[i]){
				ga[++na]=i;
			}
		}
		if(na>K){
			printf("-1\n");
			continue;
		}
		while(na<K) ga[++na]=ga[1];
		printf("10000\n");
		for(int i=1;i<=10000;i++){
			printf("%lld ",ga[(i-1)%K+1]);
		}
		printf("\n");
	}
	return 0;
}