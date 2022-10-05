#include<bits/stdc++.h>
using namespace std;
const int N=5009,P=1e9+7;
int c[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,k,a,i,j;
	cin>>n>>k,c[0]=1;
	for(i=1;i<=n;++i){
		cin>>a;
		for(j=i-1;~j;--j)c[j+1]=(c[j+1]-c[j])%P,c[j]=c[j]*1ll*a%P;
	}
	int iv=qp(n,P-2),pw=1,prod=1,ans=c[0];
	for(i=0;i<=n;++i){
		ans=(ans-pw*1ll*prod%P*c[i])%P;
		pw=pw*1ll*iv%P,prod=prod*1ll*(k-i)%P;
	}
	cout<<(ans+P)%P;
}