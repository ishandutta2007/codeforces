#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll;
typedef pair<int,int> pii;
typedef double lf; const lf err=1e-7;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
#define orz(x) {cout<<#x": "<<x<<endl;}
const int N=1020;
const int inf=1e9;
const int mod=1e9+7;
#define int ll
int fac[N],fac_inv[N];
int C(int a,int b){ //a>=b
	return fac[a]*fac_inv[a-b]%mod*fac_inv[b]%mod;
}
ll qpow(ll a,ll b,ll mod){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod; //slow
		a=a*a%mod; //slow
		b>>=1;
	}
	return ans;
}
void init(){
	fac[0]=1;
	repeat(i,1,N)fac[i]=fac[i-1]*i%mod;
	fac_inv[N-1]=qpow(fac[N-1],mod-2,mod);
	repeat_back(i,0,N-1)fac_inv[i]=fac_inv[i+1]*(i+1)%mod;
}
int n,m;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	cin>>n>>m;
	int ans=0,k=-1;
	repeat(a2,1,n+1)
	repeat(b1,a2,n+1){
		int a1=1,b2=n;
		ans+=C(a2-a1+m+k,m+k)*C(b2-b1+m+k,m+k)%mod;
		ans%=mod;
		//cout<<a1<<' '<<a2<<' '<<b1<<' '<<b2<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}