#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < count; i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> v[i];}while(0)
#define all(c) (c).begin(),(c).end()

using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
const int MODULO = 1000000007;

//BEGIN!!!

typedef struct {
	int i,m,v;
} P;
vector<P> mv;

bool mLt(const P&x,const P&y){
	return (x.m != y.m) ? less<int>()(x.m,y.m) : less<int>()(x.v,y.v);
}
int n,k,h;
bool C(double t){
	int i = 1;
	FOREACH(it,mv){
		if((double)i * h <= (*it).v * t) i++;
		if(i > k) break;
	}
	return i > k;
}

int main(){
	cin >>n>>k>>h;
	mv.resize(n);
	FOR(i,n) mv[i].i = i+1;
	FOR(i,n) cin >> mv[i].m;
	FOR(i,n) cin >> mv[i].v;
	sort(mv.begin(),mv.end(),mLt);

	double l=0,r=1e10;
	double t;
	FOR(i,100){
		//if(r-l < EPS) break;
		t = (l+r)/2;
		if(C(t)) r = t;
		else l = t;
	}
	//t *= (1 + EPS);

	int cnt = 1;
	FOREACH(it,mv){
		if((double)cnt * h <= (*it).v * t *(1+ EPS)){printf("%d ",(*it).i); cnt++;}
		if(cnt > k) break;
	}
	puts("\n");

	return 0;

}