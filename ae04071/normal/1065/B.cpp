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

int main() {
	lli n,m;
	scanf("%lld %lld",&n,&m);

	lli lo=-1,up=n+1;
	while(up-lo>1) {
		lli md=(lo+up)>>1;
		if(md*(md-1)/2<m) lo=md;
		else up=md;
	}
	printf("%lld %lld\n",max(0ll,n-m*2),n-(lo+1));

	return 0;
}