#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
ll d,mod;
ll f[31][31];

int main(){
	cin>>T;
	while(T--){
		cin>>d>>mod;
		ll D,dtmp=d;
		for(D=-1;dtmp;++D,dtmp>>=1);
		memset(f,0,sizeof(f));
		for(int i=0;i<=D;++i)f[1][i]=(i==D?(d^1<<i)+1:(1<<i));
		for(int i=2;i<=D+1;++i){
			for(int j=i-1;j<=D;++j)
			for(int k=i-2;k<j;++k){
				f[i][j]=(f[i][j]+f[i-1][k]*(j==D?(d^1<<j)+1:(1<<j))%mod)%mod;
			}
		}
		ll ans=0;
		for(int i=1;i<=D+1;++i)
		for(int j=i-1;j<=D;++j)
		(ans+=f[i][j])%=mod;
		cout<<ans<<endl;
	}
}