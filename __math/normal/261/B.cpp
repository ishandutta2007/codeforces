#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
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
#include <numeric>
#include <list>
#include <iomanip>


using namespace std;
typedef long long ll;
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

ll sum[2][51][51];

int main(){
	int n,a[50],p;
	cin>>n;
	FOR(i,n) cin>>a[i];
	cin>>p;

	sum[0][0][0] = 1;
	ll (*pv)[51],(*nt)[51];
	pv = sum[0],nt = sum[1];
	FOR(i,n){
		memcpy(nt,pv,sizeof(sum[0]));
		for(int j = 0; j < 50; j++) for(int k = 0; k <= 50; k++){
			int nxt = k + a[i];
			if(nxt <= 50){
				nt[j+1][nxt] += pv[j][k];
			}
		}
		swap(nt,pv);
	}

	double ans = 0;
	double dv = 1;
	for(int j = 1; j <= n; j++){
		dv = dv * (n-j+1) / j;
		for(int k = 0; k <= p; k++){
			ans += pv[j][k] / dv;
		}
	}

	printf("%.10lf\n",ans);

	return 0;
}