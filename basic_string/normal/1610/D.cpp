#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,P=1e9+7;
int a[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r; 
}
int jc[N],ijc[N];
int C(int n,int m){
	return jc[n]*1ll*ijc[m]%P*ijc[n-m]%P;
}
map<int,int>mp;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,m,ans=0,sum=0;
	cin>>n,jc[0]=1;
	for(i=1;i<N;++i)jc[i]=jc[i-1]*1ll*i%P;
	ijc[N-1]=qp(jc[N-1],P-2);
	for(i=N-1;i;--i)ijc[i-1]=ijc[i]*1ll*i%P;
	for(i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]%2==0)++mp[a[i]&-a[i]],++sum;
	}
	ans=(ans+qp(2,n))%P;
	ans=(ans-1)%P;
	for(auto o:mp){
		m=o.second,sum-=m;
		for(i=1;i<=m;i+=2)ans=(ans-qp(2,sum)*1ll*C(m,i))%P;
	}
	cout<<(ans+P)%P;
	return 0;
}