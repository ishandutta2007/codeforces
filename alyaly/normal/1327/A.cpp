#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,K;
signed main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>K;
		if(K%2==n%2){
			if(n>=K*K) printf("YES\n");
			else printf("NO\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}