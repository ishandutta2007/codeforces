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

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdi pair<double,int>
#define eps 1e-9


#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 1001000
using namespace std;
typedef long long ll;

double p[maxn];

double v[110];

double pfoi[110];

main(){

	int n;
	scanf("%d",&n);

	multiset<pdi> S;

	for(int i=0;i<n;i++){
		scanf("%lf",v+i);
		v[i] /= 100;
		S.insert(pdi(1e18,i));
	}

	for(int i=1;i<maxn;i++){
	
		pdi u = *--S.end();
		S.erase(S.find(u));

		int a = u.second;
		pfoi[a] = pfoi[a] + (1.0-pfoi[a]) * v[a];


		S.insert(pdi(1.0 + (1.0-pfoi[a]) * v[a] / pfoi[a], a));

		p[i] = 1;

		for(int j=0;j<n;j++)
			p[i] *= pfoi[j];

	}

	double ans = 0;

	for(int i=1;i<maxn;i++)
		ans += (p[i]-p[i-1]) * i;

	printf("%.10lf\n",ans);

}