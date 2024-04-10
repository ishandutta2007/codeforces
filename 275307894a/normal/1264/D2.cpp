#include <vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define l(x) x<<1
#define r(x) x<<1|1
#define re register
#define ll long long
#define db double
#define N 1000000
#define eps (1e-5)
#define mod 998244353
#define U unsigned
using namespace std;
int n,l1,l2,r1,r2,d;char s[N+5];ll inv[N+5],frc[N+5],now,ans;
I ll mpow(ll x,int y=mod-2){ll ans=1;while(y) y&1&&(ans=ans*x%mod),y>>=1,x=x*x%mod;return ans;}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%s",s+1);n=strlen(s+1);frc[0]=1;
	for(i=1;i<=n;i++) r1+=(s[i]==')'),r2+=(s[i]=='?');
	for(i=1;i<=n;i++) frc[i]=frc[i-1]*i%mod;now=mpow(frc[n]);for(i=n;~i;i--) inv[i]=now,now=now*i%mod;
	for(i=1;i<n;i++){
		l1+=(s[i]=='(');l2+=(s[i]=='?');r1-=(s[i]==')');r2-=(s[i]=='?');if(l1+l2<r1||r1+r2<l1) continue;d=r1+r2-l1;
		ans+=inv[l2+r2-d]*(l1*frc[l2+r2]%mod*inv[d]%mod+l2*frc[l2+r2-1]%mod*inv[d-1]%mod)%mod;
	}
	printf("%lld\n",ans%mod);
}