#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
int T,n,a[500001],K,nans,ans,la,s[500001],f[500001];
signed main(){
	cin>>n;
	for(int i=1;i<=(n+1)/2;i++){
		cin>>a[i];
	}
	cin>>la;
	for(int i=1;i<=n;i++){
		if(i>(n+1)/2) a[i]=la;
		s[i]=s[i-1]+a[i];
	}
	if(la>0){
		if(s[n]>0) printf("%lld\n",n);
		else printf("-1\n");
	}else{
		bool ffl=0;
		int ni;
		for(int i=(n+1)/2;i>=1;i=ni-1){
			for(ni=i;s[ni+n-i]-s[ni-1]>0&&ni>=1;ni--);
			if(ni==0){
				ffl=1;
				printf("%lld\n",n-i+1);
			}
		}
		if(!ffl) printf("-1\n");
	}
	return 0;
}
/*

*/