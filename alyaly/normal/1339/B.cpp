#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
int T,n,a[200003],l,r,z,na,ls,ans[200003];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i&1) printf("%lld ",a[n/2+(i+1)/2]);
			else printf("%lld ",a[n/2-i/2+1]);
		}
		printf("\n");
	}
	return 0;
}