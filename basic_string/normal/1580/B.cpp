#include<bits/stdc++.h>
using namespace std;
int n,m,k,p,f[109][109][109],jc[109],C[109][109];
bool b[109][109][109];
int dp(int n,int d,int s){
	if(b[n][d][s])return f[n][d][s];
	if(n==0)return s==0?1:0;
	if(d==m)return s==1?jc[n]:0;
	if(n==1)return s==0?1:0;
	int w=0,i,j,k,l,o;
	++d;
	for(i=0,j=n-1;~j;++i,--j){
		o=C[n-1][i];
		for(k=0,l=s;k<=i&&l>=0;++k,--l)
		if(l<=j)w=(w+dp(i,d,k)*1ll*dp(j,d,l)%p*o)%p;
	}
	b[n][--d][s]=1;
	return f[n][d][s]=w;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
cin>>n>>m>>k>>p,
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=jc[i-1]*1ll*i%p;
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	cout<<dp(n,1,k);
	return 0;
}