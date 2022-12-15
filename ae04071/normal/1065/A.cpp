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
	int test,s,a,b,c;
	scanf("%d",&test);
	while(test--) {
		scanf("%d%d%d%d",&s,&a,&b,&c);

		printf("%lld\n",s/c + 1ll*(s/c/a)*b);
	}
	return 0;
}