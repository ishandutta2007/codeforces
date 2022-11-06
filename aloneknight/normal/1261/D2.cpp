#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005,P=998244353,iv2=(P+1)/2;
int n,k,nn,kk,ans,a[N],fac[N],ifac[N];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline int C(int n,int m){return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
int main()
{
	scanf("%d%d",&n,&k);nn=n;kk=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)if(a[i]==a[i%n+1])nn--,kk=1ll*kk*k%P;
	for(int i=fac[0]=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%P;
	ifac[n]=pw(fac[n],P-2);
	for(int i=n;i;i--)ifac[i-1]=1ll*ifac[i]*i%P;
	for(int i=0;i<=nn;i++)ans=(ans+1ll*pw(k-2,i)*C(nn,i)%P*iv2%P*((nn-i)&1?pw(2,nn-i):pw(2,nn-i)-C(nn-i,(nn-i)/2)+P))%P;
	printf("%d\n",1ll*ans*kk%P);return 0;
}