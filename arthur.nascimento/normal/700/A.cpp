#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf (1<<30)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define pcc pair<char,char>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 200200	
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

#define nxt fusrf

typedef long long ll;
using namespace std;

main(){

	double  len, v1, v2;

	int np,cbus;

	cin >> np >> len >> v1 >> v2 >> cbus;

	int qbus = np/cbus;
	if(np%cbus) qbus++;

	double low = 0, up = 2e9;

	debug("qbus %d\n",qbus);

	for(int i=0;i<1000;i++){

		double mid = (low+up)/2;
		//debug("lwow %.3lf up %.3lf mid %.3lf\n",low,up,mid);

		double ss = v2 * mid;
		double sw = v1 * mid;
		double tCr = (ss-sw)/(v1+v2);

		double dsingle = sw + v1 * tCr;

		dsingle *= qbus-1;
		double left = len - dsingle;

		double tbusleft = left / v2;

		//debug("tbusleft %.2lf\n",tbusleft);

		if(tbusleft > mid)
			low = mid;
		else
			up = mid;

	}

	debug("low %.10lf\n",low);

	double Dbus = low * v2;
	double ans = low;
	double falta = len - Dbus;
	ans += falta / v1;

	printf("%.10lf\n",ans);

}