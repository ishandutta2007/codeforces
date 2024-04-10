#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3+5;
const ll mod = 998244353;
 
int n,k,a[N];
ll f[N][N<<1];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	a[n+1]=a[1];
	f[0][n]=1;
	for(int i=1;i<=n;++i){
		for(int j=n-i;j<=n+i;++j){
			if(a[i]==a[i+1])f[i][j]=f[i-1][j]*k%mod;
			else{
				f[i][j]=((j!=n-i?f[i-1][j-1]:0)+(j!=n+i?f[i-1][j+1]:0))%mod;
				(f[i][j]+=f[i-1][j]*(k-2)%mod)%=mod;
			}
		}
	}
	ll ans=0;
	for(int i=n+1;i<=2*n;++i)(ans+=f[n][i])%=mod;
	cout<<ans<<endl;
}