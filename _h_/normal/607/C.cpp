#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
typedef long long ll;
const ll md = 1e9+7;
const int mxn = 1e6+3;
int main(){
	int n;
	ll pw[mxn];
	pw[0] = 1;
	rep(i,1,mxn) pw[i] = pw[i-1]*503%md;
	char a[mxn],b[mxn];
	scanf("%d %s %s",&n,a,b);
	--n;
	rep(i,0,n) b[i] = b[i]=='N'?'S':b[i]=='S'?'N':b[i]=='W'?'E':'W';
	reverse(b,b+n);
	ll as[mxn], bs[mxn];
	as[0] = bs[0] = 0;
	rep(i,0,n){
		as[i+1] = (as[i] + pw[i]*a[i])%md;
		bs[i+1] = (bs[i] + pw[i]*b[i])%md;
	}
	rep(i,1,n+1)
		if((as[n]-as[n-i] - bs[i]*pw[n-i])%md == 0){
			puts("NO");
			return 0;
		}
	puts("YES");
}