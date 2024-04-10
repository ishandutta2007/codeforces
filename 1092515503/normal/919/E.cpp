#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,m,p,pov[1001000],res,rev[1001000],inv[1001000],bigp,invj;
signed main(){
	cin>>a>>b>>p>>m,pov[0]=1;
	for(int i=1;i<p-1;i++)pov[i]=pov[i-1]*a%p;
	inv[1]=1;
	for(int i=2;i<p;i++)inv[i]=(-(p/i)*inv[p%i]%p+p)%p;
	bigp=p*(p-1),invj=(p-1)*inv[p-1]%bigp;
	for(int i=0;i<p-1;i++){
		int j=inv[pov[i]*inv[b]%p];
		int k=(j*invj+i*p)%bigp;
		res+=m/bigp+(m%bigp>=k);
	}
	printf("%lld\n",res);
	return 0;
}