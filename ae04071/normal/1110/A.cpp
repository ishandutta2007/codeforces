#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

inline lli _abs(lli a) {return a<0 ? -a : a;}
inline int _abs(int a) {return a<0 ? -a : a;}

const int MOD=2;
int power(int a,int p) {
	int res=1;
	while(p) {
		if(p&1) res=res*a%MOD;
		a=a*a%MOD;
		p>>=1;
	}
	return res;
}
int b,n,a[100000];
int main() {
	scanf("%d%d",&b,&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	b%=MOD;
	
	int res=0;
	for(int i=0;i<n;i++) {
		a[i]%=MOD;
		res = (res + a[i]*power(b,n-i-1))%MOD;
	}
	if(res==1) puts("odd");
	else puts("even");
			
	return 0;
}