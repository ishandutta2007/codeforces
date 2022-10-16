#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef unsigned long long ull;

#define fi first
#define se second
#define gc getchar()
#define pb emplace_back
#define mem(x,v,n) memset(x,v,sizeof(x[0])*n)
#define cpy(x,y,n) memcpy(x,y,sizeof(x[0])*n)

const ld Pi=acos(-1);
const ld eps=1e-8;
const ll mod=1e9+7;

inline ll read(){
	ll x=0; bool sign=0; char s=gc;
	while(!isdigit(s))sign|=s=='-',s=gc;
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
	return sign?-x:x;
}

const int N=250+5;

ll ksm(ll a,ll b){
	ll s=1;
	while(b){
		if(b&1)s=s*a%mod;
		a=a*a%mod,b>>=1;
	}
	return s;
}
ll inv(ll x){return ksm(x%mod,mod-2);}

ll fc[N],ifc[N];
ll binom(int n,int m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}

ll n,k,ans;
int main(){
	cin>>n>>k;
	for(int i=0;i<=n;i++)fc[i]=i?fc[i-1]*i%mod:1,ifc[i]=inv(fc[i]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++){
			ll c=(n-i)*(n-j);
			ll b=binom(n,i)*binom(n,j)%mod;
			ans=(ans+(n-i+n-j&1?mod-1:1)*b%mod*ksm(k,c)%mod*ksm(k-1,n*n-c))%mod;
		}
	cout<<ans<<endl;
	return 0;
}