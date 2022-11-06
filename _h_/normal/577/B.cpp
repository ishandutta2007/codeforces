#include <cstdio>
#include <bitset>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef bitset<1000> bs;

int m,n;

bs rot(int r, const bs &b){
	bs bb = b >> (m-r);
	return bb | ((b^(bb<<(m-r)))<<r);
}

int main(){
	scanf("%d%d",&n,&m);
	bs dp(1);
	rep(_,0,n){
		int a;
		scanf("%d",&a);
		a %= m;
		bs nw = rot(a,dp);
		if(nw[0]){
			puts("YES");
			return 0;
		}
		dp |= nw;
	}
	puts("NO");
}