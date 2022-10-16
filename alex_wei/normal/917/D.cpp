#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=100+5;
const ll mod=1e9+7;

ll ksm(ll a,ll b){
	ll s=1; while(b){
		if(b&1)s=s*a%mod;
		b>>=1,a=a*a%mod;
	} return s;
}

ll n,e[N][N],a[N][N],c[N][N];
void solve(ll x){
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j){
				if(e[i][j])a[i][j]=-x;
				else a[i][j]=-1;
				a[i][i]-=a[i][j];
			}
	ll sgn=0,ans=1;
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			if(a[j][i]){
				swap(a[i],a[j]),sgn^=1;
				break;
			}
		ll inv=ksm(a[i][i],mod-2);
		for(int j=i+1;j<=n;j++)
			for(int k=n;k>=i;k--)
				a[j][k]=(a[j][k]-a[j][i]*inv%mod*a[i][k])%mod; 
	}
	for(int i=2;i<=n;i++)ans=ans*(a[i][i]+mod)%mod;
	c[x][n+1]=(sgn?mod-ans:ans)%mod;
	for(ll i=1,j=1;i<=n;i++)c[x][i]=j,j=j*x%mod;
}
void gauss(){
	memcpy(a,c,sizeof(c));
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++)
			if(a[j][i]){
				swap(a[i],a[j]);
				break;
			}
		ll inv=ksm(a[i][i],mod-2);
		for(int j=i+1;j<=n;j++)
			for(int k=n+1;k>=i;k--)
				a[j][k]=(a[j][k]-a[j][i]*inv%mod*a[i][k])%mod;
	}
	for(int i=n-1;i;i--)
		for(int j=i+1;j<=n;j++)
			a[i][n+1]=(a[i][n+1]-a[i][j]*a[j][n+1]%mod*ksm(a[j][j],mod-2))%mod;
}

int main(){
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,e[u][v]=e[v][u]=1;
	for(int i=1;i<=n;i++)solve(i);
	gauss();
	for(int i=1;i<=n;i++)cout<<(a[i][n+1]*ksm(a[i][i],mod-2)%mod+mod)%mod<<" ";
	return 0;
}