/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,m,K,S,f[2010][30],fac[200100],inv[200100],res;
pair<int,int>p[2010];
int C(int x,int y){return 1ll*fac[x+y]*inv[x]%mod*inv[y]%mod;}
int main(){
	scanf("%d%d%d%d",&n,&m,&K,&S);
	fac[0]=1;for(int i=1;i<=n+m;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n+m]=ksm(fac[n+m]);for(int i=n+m;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1;i<=K;i++)scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+K+1);
	if(p[K]!=make_pair(n,m))p[++K]=make_pair(n,m),S<<=1;
	if(p[1]!=make_pair(1,1))p[++K]=make_pair(1,1),S<<=1;
	sort(p+1,p+K+1);
	f[1][1]=1;
	for(int i=2;i<=K;i++){
		for(int k=2;k<30;k++){
			f[i][k]=C(p[i].first-1,p[i].second-1);
			for(int j=1;j<i;j++)if(p[j].first<=p[i].first&&p[j].second<=p[i].second)
				(f[i][k]+=mod-1ll*f[j][k]*C(p[i].first-p[j].first,p[i].second-p[j].second)%mod)%=mod;
		}
		for(int k=29;k>=2;k--)(f[i][k]+=mod-f[i][k-1])%=mod;
	}
	int all=C(n-1,m-1);
	for(int k=1;k<30;k++){
		S=(S+1)>>1;
		res=(1ll*S*f[K][k]+res)%mod;
		(all+=mod-f[K][k])%=mod;
	}
	(res+=all)%=mod;
	printf("%d\n",1ll*res*ksm(C(n-1,m-1))%mod);
	return 0;
}