#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#define P 1000000007
#define inf 1000001
using namespace std;
int T,n,p,a[1000001],np,nfl,ans,nx,pi;
int qread(){
	int nans=0;char c=getchar();while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		nans=nans*10+c-'0';
		c=getchar();
	}
	return nans;
}
int ksm(int x,int y){
	pi=0;
	int nans=1;
	for(;y;y>>=1){
		if(y&1){
			if(nans*x>=inf) pi=1;
			nans=nans*x%P;
		}
		if(x*x>=inf) pi=1;
		x=x*x%P;
	}
	return nans;
}
signed main(){
	T=qread();
	while(T--){
		n=qread();p=qread();ans=nx=0;
		for(int i=1;i<=n;i++){
			a[i]=qread();
		}
		sort(a+1,a+n+1);
		if(p==1){
			if(n&1) printf("1\n");
			else printf("0\n");
			continue;
		}
		for(int i=n;i>=1;i--){
			if(nx>0){
				if(nx<inf) nx--;
				ans=(ans-ksm(p,a[i])+P)%P;
			}else{
				nx=1;
				ans=(ans+ksm(p,a[i]))%P;
			}
			if(a[i]!=a[i-1]&&nx<inf&&nx!=0){
				nx=nx*ksm(p,a[i]-a[i-1]);
				if(pi||nx>=inf) nx=inf;
			}
			if(nx>inf) nx=inf;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*

*/