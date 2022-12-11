#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,K,a[201],h[201],ans;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i<n||j==1) printf("B");
				else printf("W");
			}
			printf("\n");
		}
	}
	return 0;
}