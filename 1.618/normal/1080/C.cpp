#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,cntw;
ll query_white(ll x,ll y){
	return (x * y + 1) >> 1;
}
struct Rectangle{
	ll minx,maxx,miny,maxy;
	Rectangle(ll minx = 0,ll maxx = 0,ll miny = 0,ll maxy = 0): minx(minx),maxx(maxx),miny(miny),maxy(maxy) {}
	bool illegal(){
		return minx > maxx || miny > maxy;
	}
	ll num(){
		return (maxx - minx + 1) * (maxy - miny + 1);
	}
	ll white(){
		return query_white(maxx,maxy) - query_white(minx - 1,maxy) - query_white(maxx,miny - 1) + query_white(minx - 1,miny - 1);
	}
	ll black(){
		return num() - white();
	}
}r1,r2,r3;
Rectangle intersect(Rectangle a,Rectangle b){
	ll x1 = max(a.minx,b.minx),x2 = min(a.maxx,b.maxx);
	ll y1 = max(a.miny,b.miny),y2 = min(a.maxy,b.maxy);
	return Rectangle(x1,x2,y1,y2);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&m);
		cntw = query_white(n,m);
		scanf("%I64d%I64d%I64d%I64d",&r1.minx,&r1.miny,&r1.maxx,&r1.maxy);
		cntw += r1.black();
		scanf("%I64d%I64d%I64d%I64d",&r2.minx,&r2.miny,&r2.maxx,&r2.maxy);
		cntw -= r2.white();
		r3 = intersect(r1,r2);
		if(!r3.illegal()) cntw -= r3.black();
		printf("%I64d %I64d\n",cntw,n * m - cntw);
	}
	return 0;
}