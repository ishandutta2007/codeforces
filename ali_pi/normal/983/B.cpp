#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace  :: std ;


const ll maxn=5010;

ll a[maxn];
ll f[maxn][maxn];
ll dp[maxn][maxn];
ll ff[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ff[1]=1;
	for(ll i=2;i<=n;i++){
		if(((i-1)&(-(i-1)))==i-1){
			ff[i]=1;
		}else{
			ff[i]=ff[i-1]+1;
		}
	}
	for(ll t=1;t<=n;t++){
		for(ll i=0;i+t-1<n;i++){
			ll j=i+t-1;
			if(t==1){
				f[i][j]=a[i];
			}else{
				f[i][j]=(f[i][i+ff[t]-1]^f[j-ff[t]+1][j]);
			}
		}
	}
	for(ll i=0;i<n;i++){
		dp[i][i]=f[i][i];
	}
	for(ll t=2;t<=n;t++){
		for(ll l=0;l+t-1<n;l++){
			ll r=l+t-1;
			dp[l][r]=max(dp[l+1][r],max(dp[l][r-1],f[l][r]));
		}
	}
	ll q;
	cin>>q;
	for(ll i=0;i<q;i++){
		ll l,r;
		cin>>l>>r;
		l--;
		r--;
		cout<<dp[l][r]<<endl;
	}
}