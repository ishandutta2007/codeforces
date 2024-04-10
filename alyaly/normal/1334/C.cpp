#include<bits/stdc++.h>
#pragma GCC optimize(2)
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
		ans=999999999999999999;
		n=qread();
		for(int i=1;i<=n;i++){
			a[i]=qread();
			b[i]=qread();
		}
		a[0]=a[n];
		b[0]=b[n];
		s[n]=a[n];
		for(int i=1;i<n;i++){
			if(b[i-1]<a[i]){
				s[n]+=a[i]-b[i-1];
				fl[i]=1;
			}
		}
		ans=min(ans,s[n]);
		for(int i=n-1;i>=1;i--){
			if(b[i]<a[i+1]){
				s[i]=a[i]+s[i+1]-b[i];
			}else{
				s[i]=a[i]+s[i+1]-a[i+1];
			}
			if(fl[i]){
				s[i]-=a[i]-b[i-1];
				fl[i]=0;
			}
			ans=min(ans,s[i]);
			s[i+1]=0;
		}
		s[1]=0;
		printf("%lld\n",ans);
	}
	return 0;
}
/*

*/