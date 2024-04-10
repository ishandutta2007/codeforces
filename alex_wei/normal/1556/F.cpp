#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair <int,int>;
using vint = vector <int>;

#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

const int N=14;
const ll mod=1e9+7;

ll ksm(ll a,ll b){
	ll s=1;
	while(b){
		if(b&1)s=s*a%mod;
		a=a*a%mod,b>>=1;
	} return s;
} ll inv(ll x){return ksm(x,mod-2);}
ll n,ans,a[N],win[N][N],g[N][1<<N],f[1<<N];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
				win[i][j]=a[i]*inv(a[i]+a[j])%mod;
	for(int i=0;i<n;i++)
		for(int j=0;j<1<<n;j++){
			g[i][j]=1;
			for(int k=0;k<n;k++)if(j>>k&1)g[i][j]=g[i][j]*win[i][k]%mod; 
		}
	for(int i=1;i<1<<n;i++){
		f[i]=1;
		for(int j=i-1;j;j=(j-1)&i){
			ll prod=1;
			for(int k=0;k<n;k++)
				if(j>>k&1)
					prod=prod*g[k][i^j]%mod;
			f[i]=(f[i]-f[j]*prod%mod+mod)%mod;
		}
		ll res=f[i];
		for(int k=0;k<n;k++)
			if(i>>k&1)
				res=res*g[k][((1<<n)-1)^i]%mod;
		ans=(ans+res*__builtin_popcount(i))%mod; 
	} cout<<ans<<endl;
	return 0;
}