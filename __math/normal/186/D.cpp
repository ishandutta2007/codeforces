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

double S;
int a,b,c;
double x,y,z;

double get(int u,double _){
	if(u == 0) return 0;
	return log(_) * u;
}

typedef pair<double,double> pdd;

pdd get_pdd(double sum)
{
	if(b == 0) return pdd(0,sum);
	double t = sum *  b / (b + c);
	return pdd(t,sum - t);
}

double get_(int x,double _)
{
	if(x== 0) return 0;
	return x * log(_) * 100;
}

double get_log(double n)
{
	x = n;
	pdd p = get_pdd(S - n);
	y = p.first,z = p.second;
	return get_(a,x) + get_(b,y) + get_(c,z);
}

int main(){

	cin >> S >> a>>b>>c;
	if(a ==0){
		x = 0;
		pdd p = get_pdd(S);
		y = p.first,z = p.second;
	} else {
		double lb = 0,ub = S;
		for(int i = 0; i < 300; i++){
			double m1 = lb * 3 / 4 + ub / 4;
			double m2 = lb / 4 + ub * 3 / 4;
			double len1 = get_log(m1);
			double len2 = get_log(m2);
			if(len1 > len2){
				ub = m2;
			} else if( len1 < len2){
				lb = m1;
			}
			else {
				double len1 = get_log((m1 + m2) / 2);
				break;
			}
		}
	}

	double diff = x + y + z - S;
	diff /= 3;
	x -= diff;
	y -= diff;
	z -= diff;

	printf("%.15f %.15f %.15f",x,y,z);

	return 0;
}