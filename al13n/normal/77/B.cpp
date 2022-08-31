#include <string>
#include <memory.h>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <utility>
#pragma comment (linker, "/STACK:90000000")
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-9
#define iinf 1000000000
using namespace std;



int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	forn(i,tc){
		double a,b;
		cin>>a>>b;
		double r;
		if(b==0)
			r=1;
		else if(a==0)
			r=0.5;
		else{

		if(4*b<a)
			r=2*a*b-2*b*b;
		else
			r=a*b+a*a/8;
		r/=2*a*b;
		}
		printf("%.10lf\n",r);
	}

	return 0;
}