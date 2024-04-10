#include<bits/stdc++.h>
#define mod 998244353
#define n2 499122177
using namespace std;
auto powdv(auto x,auto y){
	int ans=1;
	while(y){
		if(y&1)ans=ans*x%mod;
		y>>=1,x=x*x%mod;
	}
	return ans;
}
long long f1[1<<17],f2[1<<17],f3[1<<17];
int f[1<<17];
void ggg(auto &x,auto &y){
	auto xx=x,yy=y;
	x=xx+yy,y=xx-yy;
}
void hhh(auto &x,auto &y){
	auto xx=x,yy=y;
	x=1ll*(xx+yy)*n2%mod;
	y=1ll*(xx-yy)*n2%mod;
}
int main(){
	int n,k;
	cin>>n>>k;
	int x,y,z;
	cin>>x>>y>>z;
	int tt=0;
	for(int i=1;i<=n;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a^=c,b^=c,tt^=c;
		++f1[a],++f2[b],++f3[a^b];
	}
	for(int i=1;i<(1<<k);i<<=1)
		for(int j=0;j<(1<<k);j+=i,j+=i)
			for(int l=j;l<j+i;++l){
				ggg(f1[l],f1[l+i]);
				ggg(f2[l],f2[l+i]);
				ggg(f3[l],f3[l+i]);
			}
	for(int i=0;i<(1<<k);++i){
		long long B=(f1[i]+n)/2,C=(f2[i]+n)/2,D=(f3[i]+n)/2;
		long long a=(B+C+D-n)/2;
		long long b=B-a,c=C-a,d=D-a;
		f[i]=1;
		f[i]=1ll*f[i]*powdv(0ll+x+y+z,a)%mod;
		f[i]=1ll*f[i]*powdv(0ll+x-y+z,b)%mod;
		f[i]=1ll*f[i]*powdv(0ll-x+y+z,c)%mod;
		f[i]=1ll*f[i]*powdv(0ll-x-y+z,d)%mod;
	}
	for(int i=1;i<(1<<k);i<<=1)
		for(int j=0;j<(1<<k);j+=i,j+=i)
			for(int l=j;l<j+i;++l){
				hhh(f[l],f[l+i]);
			}
	for(int i=0;i<(1<<k);++i)f[i]=(f[i]+mod)%mod;
	for(int i=0;i<(1<<k);++i)printf("%d ",f[i^tt]);
	return 0;
}