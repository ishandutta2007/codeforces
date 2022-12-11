#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
using namespace std;
int T,n;
int a[300001],b[300001],s[300001],fl[300001],ans=999999999999999999;
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
	while(T--){
		n=qread();
		printf("%lld\n",n);
	}
	return 0;
}
/*

*/