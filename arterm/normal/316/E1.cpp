#include <iostream>

#define mod 1000000000
#define M 111
#define long long long

using namespace std;

int n,a[M],f[M],m;

void pre(void){
	f[0]=f[1]=1;
	for (int i=2; i<M; ++i){
		f[i]=f[i-1]+f[i-2];
		if (f[i]>=mod)
		f[i]-=mod;
	}
}

void que(int l, int r){
	long ans=0;
	for (int i=l,t=0; i<=r; ++i,t++)
	ans=(ans+1ll*f[t]*a[i])%mod;
	cout<<ans<<"\n";
}

void read(void){
	cin>>n>>m;
	
	for (int i=1; i<=n; ++i)
	cin>>a[i];
	
	for (int i=0,l,r,x,y,t; i<m; ++i){
		cin>>t;
		if (t==1){
			cin>>x>>y;
			a[x]=y;
		}
		if (t==2){
			cin>>l>>r;
			que(l,r);
		}
	}
}

int main()
{
	pre();
	read();
	return 0;
}