#include<bits/stdc++.h>
using namespace std;
enum{N=5009};
int jc[N],ijc[N],n,P,p1[N];
int qp(int a,int b){int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;return r;}
int C(int n,int m){
	if(n<m||m<0)return 0;
	return jc[n]*1ll*ijc[m]%P*ijc[n-m]%P;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j,s=0,pi;
	cin>>n>>P;
	for(jc[0]=p1[0]=i=1;i<=n;++i)jc[i]=jc[i-1]*1ll*i%P,p1[i]=p1[i-1]*(n-1ll)%P;
	for(ijc[n]=qp(jc[n],P-2),i=n;i;--i)ijc[i-1]=ijc[i]*1ll*i%P;
	for(i=0;i<n;++i)for(j=i,pi=1;~j;--j,pi=pi*1ll*(n-i)%P)
	s=(s+C(n,i)*1ll*C(i,j)%P*C(n-i,n-i-j)%P*pi%P*p1[j]%P*jc[n-i-1]%P*j)%P;
	cout<<s;
}