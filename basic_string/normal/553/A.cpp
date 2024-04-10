#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int main(){
	int n,ans=1,i,j,k=0,l;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>j,ans=ans*1ll*j%P;
		for(l=1;l<j;++l)ans=ans*1ll*(k+l)%P;
		for(l=1;l<=j;++l)ans=ans*1ll*qp(l,P-2)%P;
		k+=j;
	}
	cout<<ans;
	return 0;
}