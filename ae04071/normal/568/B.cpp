#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli mod=1e9+7;
int n;
lli com[4001][4001],fac[8001],cat[4001];

lli power(lli a,lli p) {
	lli res=1;
	while(p) {
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
lli inv(lli a) {return power(a,mod-2);}

int main() {
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=2*n;i++) fac[i]=fac[i-1]*i%mod;
	com[0][0]=1;
	for(int i=1;i<=n;i++) for(int j=0;j<=i;j++){
		if(i==j || j==0) com[i][j]=1;
		else com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
	}
	cat[0]=cat[1]=1;
	for(int i=2;i<=n;i++) {
		for(int j=0;j<i;j++) cat[i]=(cat[i] + cat[j]*com[i-1][j]%mod)%mod;
	}

	lli ans=0;
	for(int i=0;i<n;i++) {
		ans = (ans + com[n][i]*cat[i]%mod)%mod;
	}
	printf("%lld\n",ans);

	return 0;
}