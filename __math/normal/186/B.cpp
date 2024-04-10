#define _USE_MATH_DEFINES
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
#define FOR(i,count) for (int i = 0; i < (count); i++)

using namespace std;

static const double EPS = 1e-10;
const int MODULO = 1000000007;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!
typedef pair<double,int> P;

int n,t1,t2;
double k;
int a[1001],b[1001];
double l[1001];

bool comp(const P& x,const P& y)
{
	return greater<double>()(x.first,y.first);
}

double get_len(int i){
	double x = a[i],y = b[i];
	double ret = x * t1 * k + y * t2;
	ret = max(ret ,y * t1 * k + x * t2);

	return ret;
}

int main(){
	cin >> n>>t1>>t2>>k;
	k = (100 - k) / 100;
	FOR(i,n) cin >> a[i] >> b[i];

	vector<P> p;
	FOR(i,n){
		double t = get_len(i);
		p.push_back(P(t,i+1));
	}

	stable_sort(p.begin(),p.end(),comp);

	FOR(i,n){
		printf("%d %.2f\n",p[i].second,p[i].first);
	}

	return 0;
}