#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

inline int _abs(int a) {return a<0 ? -a : a;}
inline lli _abs(lli a) {return a<0 ? -a : a;}

const int mod=998244353;

lli power(lli a,lli p) {
	lli res=1;
	while(p) {
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
lli inv(lli a) {
	return power(a,mod-2);
}
int n,m,a,b[200001];
int main() {
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<=m;i++)
		scanf("%d",b+i);

	lli ans=1,t;
	for(int i=0;i<m;i++){
		lli val=power(a,b[i+1]-b[i]);
		ans = ans*val%mod*(val+1)%mod*inv(2)%mod;
	}
	ans=ans*power(a,n-b[m]*2)%mod;

	printf("%lld\n",ans);

	return 0;
}