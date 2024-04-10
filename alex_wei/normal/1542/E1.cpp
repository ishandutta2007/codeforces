#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=505;

int n,mod,ans,f[N][N*N/2],s[N][N*N/2],tmpp[N*N/2],tmps[N*N/2];
int main(){
	cin>>n>>mod,f[1][0]=s[1][0]=s[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i*(i-1)/2;j++){
			f[i][j]=(s[i-1][j]-(j<i?0:s[i-1][j-i])+mod)%mod;
			s[i][j]=((j?s[i][j-1]:0)+f[i][j])%mod;
		}
		for(int j=i*(i-1)/2+1;j<=i*(i+1)/2;j++)s[i][j]=s[i][j-1];
		if(i<=3)continue;
		int lim=(i-1)*(i-2)/2;
		for(int j=0;j<=lim;j++){
			tmpp[j]=((j==0?0:tmpp[j-1])-1ll*s[i-1][j]*j%mod+mod)%mod,
			tmps[j]=((j==0?0:tmps[j-1])+s[i-1][j])%mod;
		}
		ans=1ll*ans*i%mod;
		for(int j=0;j+2<=lim;j++){
			int times=min(lim-j-1,i-1),c=(i-1+i-times)*times/2;
			ans=(ans+1ll*f[i-1][j]%mod*s[i-1][lim]%mod*c)%mod;
			int r=min(lim-1,j+i-1);
			ans=(ans-1ll*f[i-1][j]*(tmpp[r]-tmpp[j]+1ll*(tmps[r]-tmps[j])*(i+j)%mod)%mod+mod)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}