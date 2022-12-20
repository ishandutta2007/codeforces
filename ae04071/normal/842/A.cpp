#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cassert>
#include <cmath>

using namespace std;
typedef long long lli;
typedef pair<int,int> ip;
typedef pair<lli,int> lip;

inline double ABS(double a) {
	return a<0?-a:a;
}
inline double POWER(double a) {
	return a*a;
}
inline lli ABS(lli a) {
	return a<0?-a:a;
}
inline int ABS(int a) {return a<0?-a:a;}
inline lli POWER(lli a) { return a*a; }
inline lli GCD(lli a,lli b) {
	while(b) {
		lli tmp=a%b;a=b;b=tmp;
	}
	return a;
}
const double EPS=1e-9;
const int MOD=1e9+7;
const lli INF=1e15;
const int dy[4]={0,-1,0,1},dx[4]={1,0,-1,0};


int main() {
	lli l,r,x,y,k;
	scanf("%lld %lld %lld %lld %lld",&l,&r,&x,&y,&k);
	for(lli b=x;b<=y;b++) {
		lli t=b*k;
		if(t>=l&&t<=r) {
			puts("YES");
			return 0;
		}
		if(t>r) break;
	}
	puts("NO");
	return 0;
}