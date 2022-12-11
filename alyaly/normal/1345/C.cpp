#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
//#define P 998244353
using namespace std;
int T,n,m,a[200001],p[200001],ffl;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		ffl=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]=a[i]+1000000000*n;
			a[i]%=n;
			a[i]+=i-1;
			a[i]%=n;
			p[a[i]]=T+1;
		}
		for(int i=0;i<n;i++){
			if(p[i]!=T+1){
				ffl=1;
			}
		}
		if(ffl) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
/*

*/