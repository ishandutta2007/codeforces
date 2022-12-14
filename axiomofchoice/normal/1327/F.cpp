#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=[]{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
typedef long long ll;
const int N=500010;
const int mod=(0?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int l[N],r[N],x[N],last[N],v[N],dp[N];
ll sum[N];
int n,m,k;
int main(){
	cin>>n>>k>>m;
	ll ans=1;
	repeat(i,0,m)cin>>l[i]>>r[i]>>x[i];
	repeat(i,0,k){
		dp[0]=sum[0]=1;
		repeat(j,1,n+2)last[j]=v[j]=0;
		repeat(j,0,m)
		if((x[j]>>i)&1){
			++v[l[j]];
			--v[r[j]+1];
		}
		else last[r[j]+1]=max(last[r[j]+1],l[j]);
		repeat(j,1,n+2){
			v[j]+=v[j-1];
			last[j]=max(last[j],last[j-1]);
		}
		repeat(j,1,n+2){
			if(!v[j]){
				dp[j]=sum[j-1];
				if(last[j])
					dp[j]=(dp[j]-sum[last[j]-1])%mod;
			}
			else dp[j]=0;
			sum[j]=(sum[j-1]+dp[j])%mod;
		}
		ans=ans*dp[n+1]%mod;
	}
	cout<<(ans+mod)%mod<<endl;
}